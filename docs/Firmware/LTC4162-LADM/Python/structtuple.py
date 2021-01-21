"""structtuple.py: a library for dynamically creating typed namedtuples.

A structtuple is a subclass of Python's standard namedtuple, created at run-time,
that adds byte sequence serialization and deserialization abilities
from Python's struct module.
"""

# Copyright 2018 by Analog Devices, Inc.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.

import struct
from collections import namedtuple, Sequence, OrderedDict

class ParseException(Exception):
    "byte sequence to structtuple conversion exception superclass"
    pass
class NotEnoughBytes(ParseException):
    "deserializer wasn't given enough bytes to satisfy the struct format."
    pass
class NoMatch(ParseException):
    """deserializer is certain that a matching structtuple cannot be constructed from the head of
       the given sequence of bytes.

       Attribute 'rejected' contains the structtuple that failed to match."""
    rejected = None

def make_structtuple_class(struct_name, endianness='>', fieldlist=(('databytes', None))):
    '''Returns a new structtuple class with specified field names and data types.
       Example usage:

            time_pkt = make_structtuple_class(struct_name="time_pkt",
                                              endianness='>',
                                              fieldlist=[("src_ID", "H"),
                                                         ("trans_ID", "L"),
                                                         ("microsecs", "L"),
                                                         ("verb", "B"),
                                                         ("noun", "B"),
                                                         ("extrabytes", None)])

       where fieldlist is a dictionary mapping field names to types defined by
       Python struct.unpack_from() format strings. If the last field is mapped to None,
       it becomes a 'catch-all' field that receives a sequence of all bytes left over
       after the from_bytes() constructor described below has parsed out all preceding
       fields.

       The above creates a namedtuple subclass called 'time_pkt'. Now calling

            pkt = time_pkt.from_bytes(byteseq)  # byteseq is a string or sequence of bytes

       returns a time_pkt 'pkt' where:

            pkt.src_id == first two bytes of byteseq interpreted as an unsigned 16-bit integer
                          in big-endian order,
            pkt.trans_ID == the next four bytes interpreted as an unsigned 32-bit integer,
            pkt.microsec == the four bytes after that, similarly interpreted as
                            an unsigned 32-bit integer,
            pkt.verb == the following byte,
            pkt.noun == the next byte (the twelfth byte of byteseq), and
            pkt.extrabytes == a sequence of all remaining bytes, acting as the 'catch-all' field.

       As a concrete example:

           pkt = time_pkt.from_bytes("Analog Devices, Inc.")
           print pkt

       results in

           time_pkt(src_ID=16750, trans_ID=1634496359, microsecs=541353334,
                    verb=105, noun=99, extrabytes='es, Inc.')

       being printed to the terminal. Notice that 16750 == 0x416e, 1634496359 == 0x616c6f67,
       and that:

            chr(0x41)=='A', chr(0x6e)=='n', chr(0x61)=='a',
            chr(0x6c)=='l', chr(0x6f)=='o', chr(0x67)=='g',

       spelling 'Analog'.

       The from_bytes() constructor is also capable of filtering operations if passed a
       matching template against which to match the fields of a newly-deserialized structtuple.
       Consult the online help / docstring for from_bytes() for more info.
       E.g. help(time_pkt.from_bytes)  in this example.
       '''
    # Validate arguments:
    assert isinstance(struct_name, basestring)
    assert len(struct_name) >= 1
    assert isinstance(endianness, str)
    assert len(endianness) == 1
    valid_endiannesses = ('>', '<', '!')  # Disallow 'native' endianness to avoid incompatibilities.
    assert endianness in valid_endiannesses, \
        ("Endianness must be one of {}. Got '{}' "
         "instead").format(valid_endiannesses, endianness)
    assert isinstance(fieldlist, Sequence)
    position = 0
    longest_field_name_length = 0
    catchall_field_name = None
    # Validate format strings and assemble struct format string
    struct_fmt = endianness # First character specifies endianness.
    types_dict = OrderedDict()
    for field in fieldlist:
        assert isinstance(field, tuple)
        assert len(field) == 2
        assert isinstance(field[0], basestring), \
            "Field name {} isn't a string.".format(field[0])
        assert field[0] not in types_dict, \
            "Duplicate field name '{}' in fieldlist {}".format(field, fieldlist)
        types_dict[field[0]] = field[1]
        if field[1] is None and position == len(fieldlist) - 1:
            # If last field, None format means the parser will
            # place all remaining unparsed bytes into that field.
            catchall_field_name = field[0]
        else:
            assert isinstance(field[1], str), \
                ("Struct format {} for {} isn't "
                 "a string.").format(field[1], field[0])
            try:
                struct.calcsize(field[1])
            except struct.error:
                raise ValueError, ("In field '{}', '{}' is not "
                                   "a valid struct format "
                                   "string.").format(field[0], field[1])
            # field[1] is a valid struct format string
            struct_fmt += field[1]
        if len(field[0]) > longest_field_name_length:
            longest_field_name_length = len(field[0])
        position += 1
    # Check that concatenating all the field format strings
    # gives a valid format string.
    try:
        fmt_length = struct.calcsize(struct_fmt)
    except struct.error:
        raise ValueError, ("struct_fmt {} must be a valid Python struct "
            "format string.").format(struct_fmt)
    # Create base class namedtuple with the given field names
    fields = tuple(field[0] for field in fieldlist)
    _structure = namedtuple("_"+struct_name, fields)
    # Instance methods to put into new structtuple subclass:
    #
    # 1. Custom __repr__() method.
    def class_repr(self):
        """Returns a string representation of a {struct_name} object."""
        fields = self._asdict()
        param_string = ", ".join(["{}={}".format(name, repr(fields[name])) for name in fields])
        return "{cls.__name__}({param_string})".format(cls=self.__class__, param_string=param_string)
    class_repr.__name__ = "__repr__"
    class_repr.__doc__ = class_repr.__doc__.format(struct_name=struct_name)
    # 2. Serialization method. Tells a structtuple to return a sequence of bytes
    # representing its contents.
    def to_bytes(self):
        """Returns a representation of a {struct_name} as a sequence of bytes,
        using {endian} conversions as needed.
        The sequence can later be fed to the from_bytes constructor to recreate
        the {struct_name}."""
        if self._catchall_field_name is not None:
            # "Last field for unparsed bytes" feature being used in this structtuple.
            result = bytearray(self._fmt_length+len(self[-1]))  # Make correct-length buffer
            struct.pack_into(self._struct_fmt, result, 0, *self[:-1])
            result[self._fmt_length:] = self[-1]
        else:
            # Case where all fields correspond to formats
            result = bytearray(self._fmt_length)
            struct.pack_into(self._struct_fmt, result, 0, *self)
        return result
    endiantext = {'>': "big-endian", '!': "big-endian", '<': "little-endian"}
    to_bytes.__doc__ = to_bytes.__doc__.format(struct_name=struct_name,
                                               endian=endiantext[endianness])
    #
    # The following is the from_bytes() constructor for our new structtuple class.
    # Notice that constructors have to be class methods (or static methods) and not instance methods
    # because they are what you call to create an instance in the first place.
    # We first define from_bytes() as a ordinary function so that we can autogenerate its __doc__
    # string. Then we will decorate it with the classmethod() decorator when we insert it into
    # new structtuple class dictionary.
    # (In Python 2.7, the docstrings of class methods are read-only. This works around that.)
    def from_bytes(cls, byteseq, match_values=None):
        """Given a sequence of bytes and a matching template, parse the bytes into a {struct_name}
        with fields named {field_names},
        using the Python struct format string '{struct_fmt}'.
        {field_for_extra_bytes}

        This function is a constructor for {struct_name}.

        match_values is an optional sequence (e.g. tuple) of values to match against the
        newly constructed {struct_name}.
        If match_values is None or not given, then the {struct_name} is simply returned.

        If match_values is given and isn't None, its elements are compared with the {struct_name}'s,
        and the {struct_name} is returned if they all match
        i.e. match_values[i] == {struct_name}[i] for all i in range(len(match_values)).

        None values within match_values are interpreted as wildcards.

        To support matching schemes more sophisticated than "==" comparison, any element of match_values
        can also be a function returning True or False (i.e. predicate function),
        which will be called with the corresponding {struct_name} field value as the first argument
        and the entire {struct_name} as the second:

            function(field_val, the_whole_{struct_name})

        If the function returns True, that comparison is considered to have succeeded.

        Raises exception NoMatch if the bytes result in a {struct_name} that doesn't match match_values.
        The NoMatch exception's 'rejected' attribute will contain the rejected {struct_name}.

        Raises exception NotEnoughBytes if there aren't enough bytes in byteseq to satisfy
        struct format string '{struct_fmt}'."""
        # Validate arguments:
        assert isinstance(cls, type)
        # Couldn't use assert isinstance(byteseq, Sequence) because apparently array.array()s aren't
        # considered Sequences, so here's the next best thing:
        assert hasattr(byteseq, '__getitem__') and hasattr(byteseq, '__len__'), \
            "byteseq={} must be a Sequence of byte-sized values"
        assert match_values is None or isinstance(match_values, Sequence)
        if len(byteseq) < fmt_length:
            raise NotEnoughBytes, "not enough bytes in {} for struct format '{}'".format(byteseq, struct_fmt)
        unpacked = struct.unpack_from(struct_fmt, byteseq)
        if len(unpacked) + 1 == len(fields):
            # There's an extra field into which we'll put the remaining unparsed bytes.
            unpacked = unpacked + (byteseq[fmt_length:],)
        elif len(unpacked) == len(fields):
            pass  # unpacked into exactly the number of fields specified
        elif len(unpacked) > len(fields):
            raise TypeError, ("not enough fields ({}) to receive the parsed values "
                              "from struct_fmt '{}'").format(len(fields), struct_fmt)
        elif len(unpacked) + 1 < len(fields):
            raise TypeError, ("It's ambiguous which fields ({}) "
                              "should receive the unparsed bytes").format(", ".join(fields[len(unpacked):]))
        else:
            raise Exception, ("BUG: Case not covered in from_bytes()'s argument validation "
                              "for the case where len(unpacked) == {} and len(fields) == {}"
                              "").format(len(unpacked), len(fields))
        # Create the new structtuple we may be returning. (cls == structtuple_class when called)
        result = _structure.__new__(cls, *unpacked)
        # Return result if match_values template is satisfied, else raise an exception:
        if match_values is None:
            pass  # no matching template given so simply return result
        elif len(match_values) > len(result):
            raise NoMatch, "{} doesn't have enough fields to match {}".format(result, match_values)
        elif reduce(lambda x, y: x and y,  # Entire template has to match.
                    [val[0] is None  # Wildcard matches anything.
                     or val[0] == val[1]  # Equal values match.
                     or (hasattr(val[0], "__call__")  # Predicate function f returns True, with f as
                         and val[0](val[1], result))  # f(this_field_value, tuple_of_all_fields)
                     for val in zip(match_values, result)]):
            pass  # fields match the given template
        else:
            e = NoMatch("{} didn't match template {}".format(result, match_values))
            e.rejected = result
            raise e
        return result
    # __doc__ string autogeneration for from_bytes():
    #
    # Try out the struct_fmt string to find out how many fields it unpacks, knowledge of which
    # will help us dynamically write a better parser docstring below.
    num_struct_fields = len(struct.unpack_from(struct_fmt, 'A' * fmt_length))
    if len(fields) == num_struct_fields + 1:
        field_for_extra_bytes = "Any unparsed bytes will be placed in the '{}' field.".format(fields[-1])
    else:
        field_for_extra_bytes = ""
    # Update from_byte()'s docstring with the actual structtuple class name and field names.
    from_bytes.__doc__ = from_bytes.__doc__.format(struct_name=struct_name, struct_fmt=struct_fmt,
        field_names=", ".join(("'{}'".format(field) for field in fields)),
        field_for_extra_bytes=field_for_extra_bytes)
    #
    # __doc__ string for the new structtuple class:
    docstring = "A namedtuple with typed fields.\n"
    fieldname_fmt = "{{:>{}s}}: {{}}\n".format(longest_field_name_length+2)
    catchall_fmt = "{{:>{}s}}: {{}}\n".format(longest_field_name_length)
    for field in (types_dict if catchall_field_name is None else OrderedDict(types_dict.items()[:-1])):
        docstring += fieldname_fmt.format(field, repr(types_dict[field]))
    if catchall_field_name is not None:
        docstring += catchall_fmt.format(catchall_field_name, "sequence of leftover bytes, if any")
    #
    # Create and return a namedtuple subclass with the specified fields
    # to which we'll add a from_bytes() constructor (aka. deserializer)
    # and a to_bytes() instance method (aka. serializaer).
    structtuple_class = type(struct_name, (_structure,),
                             {# class data attributes:
                                "__slots__": (), "__doc__": docstring,
                                "_types_dict": types_dict,
                                "_struct_fmt": struct_fmt, "_fmt_length": fmt_length,
                                "_catchall_field_name": catchall_field_name,
                              # class methods:
                                "from_bytes": classmethod(from_bytes),
                              # object instance methods:
                                "__repr__": class_repr, "to_bytes": to_bytes})
    return structtuple_class

if __name__ == "__main__":
    time_pkt = make_structtuple_class(struct_name="time_pkt",
                                      endianness='>',
                                      fieldlist=[("src_ID", "H"),
                                                 ("trans_ID", "L"),
                                                 ("microsecs", "L"),
                                                 ("verb", "B"),
                                                 ("noun", "B"),
                                                 ("extrabytes", None)])
    labcomm_packet = make_structtuple_class("labcomm_packet", ">",
                                            (('sop', 'H'),
                                             ('src_id', 'H'),
                                             ('dest_id', 'H'),
                                             ('length', 'H'),
                                             ('dataAndCRC16', None)))
    cmds = ["labcomm_packet",
            "type(labcomm_packet)",
            "msg = 'Analog Devices, Inc.'",
            "labcomm_packet.from_bytes(msg)",
            "pkt = labcomm_packet.from_bytes(msg)",
            "pkt.to_bytes()",
            "pkt.to_bytes() == msg",
            "print",
            ("tpkt = time_pkt(src_ID=0xcafe, trans_ID=0x6789abcd, microsecs=100, "
             "verb=0x1, noun=0x4, extrabytes='AB')"),
            "tpkt.to_bytes()",
            "time_pkt.from_bytes(tpkt.to_bytes())",
            "tpkt == time_pkt.from_bytes(tpkt.to_bytes())",
            "tpkt2 = time_pkt.from_bytes(msg)",
            "tpkt2"]
    for cmd in cmds:
        try:
            print "{}: {}".format(cmd, repr(eval(cmd)))
        except SyntaxError:
            try:
                exec(cmd)
                print "Executed statement:\n    {}".format(cmd)
            except Exception as e:
                print "Unable to parse\n    {}\n  as a valid Python expression or statement."
                print
                print e