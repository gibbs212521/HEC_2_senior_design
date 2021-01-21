"""Simple Python command shell for interacting with a demoboard."""

# Copyright 2019 by Analog Devices, Inc.
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

device_name = "LTC4162"  # Name to look for in demoboard's QuikEval 'I' response string.

if __name__=='__main__':
    from serial import Serial
    from serial.tools.list_ports import comports
    from serial.serialutil import SerialException, SerialTimeoutException
    from portable_labcomm_api import SMBus_Labcomm_interface, SMBus_Exception, i2c_error, PEC_error
    import sys
    while True:
        comport_list = [port for port in comports() if (port.vid and port.pid)]
        if not len(comport_list):
            print "I couldn't find your demoboard. (No USB/serial devices found.)"
            print "Try unplugging and replugging the demoboard's USB connection."
            print
            print "*** For greatest reliability, connect the demoboard directly to a USB port on this computer"
            print "      without going through any hubs."
            print
            raw_input("\nPress ENTER to exit.")
            raise SystemExit
        possible_demoboard_comports = [port for port in comport_list
                                       if port.vid == 0x1272 and port.pid == 0x8005]
        ltc_demoboards = {}
        for port in possible_demoboard_comports:
            ser = None
            try:
                ser = Serial(port.device, timeout=1, write_timeout=1)
                ser.write('i')
                board_type_str = ser.read(50)
                board_type = board_type_str.split(',')
                if (len(board_type) < 3
                    or board_type[0] != 'USBSPI'
                    or not board_type[2].startswith('Labcomm')):
                    continue  # Definitely not an LTC demoboard that talks Labcomm
                ser.write('I')
                id_str = ser.read(50)
                id_tuple = id_str.split(',')
                if len(id_tuple) < 6 or not id_tuple[0].startswith(device_name):
                    continue  # Definitely not a demoboard for our device
                ltc_demoboards[port.device] = (id_tuple[0], id_tuple[6])
            except SerialException as e:
                pass
            finally:
                if ser is not None:
                    ser.close()
        if not len(ltc_demoboards):
            print
            print ("No {} demoboards appear to be connected to a USB port "
                   "on this computer.".format(device_name))
            print
            print "If you're certain there is a {} demoboard connected,".format(device_name)
            print "please disconnect that demoboard from its USB cable and"
            print "reconnect the demoboard DIRECTLY to a USB port on the computer,"
            print "that is, WITHOUT going through any external hubs."
            print
            print "Try re-running this program afterwards."
            print
            print "Another possibility, if you've already tried the advice above without success,"
            print "is that the stock firmware that the demoboard shipped with has been overwritten."
            print "This interactive Python example depends on that firmware (a.k.a. 'Labcomm firmware')."
            print "For firmware re-installation instructions, type the word 'firmware'"
            print "before pressing ENTER below."
            print
            reply = raw_input("\nPress ENTER to exit.")
            if reply.lower() == "firmware":
                print
                print
                title = "How to re-install 'Labcomm firmware' onto your {} demoboard:".format(device_name)
                print title
                print "=" * len(title)
                print
                print "Install Arduino IDE version 1.8.7 or later from https://www.arduino.cc/en/Main/Software"
                print "if you don't already have it."
                print
                print "In Windows Explorer, double-click on DemoboardSketch.ino"
                print "inside the 'MZeroSketchbook' folder in this SDK."
                print "This will launch Arduino IDE and open DemoboardSketch.ino."
                print
                print "If you're on Linux, MacOS, or another platform that supports Arduino IDE,"
                print "you may need to open Arduino IDE first, click File -> Open... , then navigate"
                print "to MZeroSketchbook/DemoboardSketch/DemoboardSketch.ino ."
                print
                print "Click on Tools -> Board: -> Boards Manager , and install the"
                print "'Arduino SAMD Boards' version 1.6.20 or later."
                print
                print "Click on File -> Preferences , and change Sketchbook location to be the path"
                print "to the MZeroSketchbook folder."
                print
                print "Plug in your {} demoboard via USB.".format(device_name)
                print
                print "Click on Tools -> Port . Select the port corresponding to the {} demoboard.".format(device_name)
                print
                print "Compile and upload the sketch to your {} demoboard.".format(device_name)
                print
                raw_input("\nPress ENTER to exit.")
            raise SystemExit
        print "I found the following serial ports on this computer"
        print "that appear to be connected to a {} demoboard:".format(device_name)
        for port in ltc_demoboards:
            print " {:>12s} : {} demoboard {} ".format(port,
                                                       ltc_demoboards[port][0],
                                                       ltc_demoboards[port][1])
        serial_port = raw_input("Which serial port should I use to talk to the demoboard "
                                "(e.g. {})? ".format(port))
        if serial_port == "" and len(ltc_demoboards) == 1:
            serial_port = port  # in case user just presses ENTER and there's only one board.
            print "Assuming you meant {}...".format(port)
        if serial_port not in ltc_demoboards:
            print
            print "{} isn't connected to any of the boards I found.".format(serial_port)
            print
            continue
        try:
            demoboard = SMBus_Labcomm_interface(serial_port, debug=False)
            break  # Succeeded in opening serial port
        except SerialException as e:
            print "I couldn't open port '{}'.".format(serial_port)
            print "Caught exception: {}".format(e)
            print
    import LTC4162_LADM as LTC4162
    chip = LTC4162.LTC4162(read_function=demoboard.read_word,
                           write_function=demoboard.write_word,
                           verbose=False)
    dashboard_channel_universe = ['telemetry_valid', 'chem',
                                  'charge_current_setting',
                                  'vcharge_setting', 'vabsorb_delta',
                                  'charger_state', 'charge_status',
                                  'en_jeita', 'equalize_req', 'mppt_en']
    # Keep only bitfields that exist in this IC variant.
    dashboard_channel_names = []
    for chname in dashboard_channel_universe:
        if hasattr(chip, chname):
            dashboard_channel_names.append(chname)
    telemetry_channel_names = ['vin', 'vbat', 'ibat', 'iin',
                               'thermistor_voltage',
                               'die_temp',
                               'cell_count'
                               ]
    ascii_unicode_approx_table = \
       { ord(u'\N{DEGREE SIGN}'):                 u'_deg_',
         ord(u'\N{MULTIPLICATION SIGN}'):         u'x',
         ord(u'\N{GREEK SMALL LETTER MU}'):       u'u',    # preferred micro sign
         ord(u'\N{MICRO SIGN}'):                  u'u',    # deprecated micro sign
         ord(u'\N{REGISTERED SIGN}'):             u'(R)',
         ord(u'\N{PLUS-MINUS SIGN}'):             u'+/-',
         ord(u'\N{SUPERSCRIPT TWO}'):             u'^2',
         ord(u'\N{GREEK CAPITAL LETTER OMEGA}'):  u'_ohm', # preferred ohm symbol
         ord(u'\N{OHM SIGN}'):                    u'_ohm', # deprecated ohm symbol
         ord(u'\N{GREEK SMALL LETTER BETA}'):     u'Beta',
         ord(u'\N{COMBINING OVERLINE}'):          u'_overbar',
         ord(u'\N{INFINITY}'):                     u'inf',
         ord(u'\N{SQUARE ROOT}'):                  u'_sqrt_',
         ord(u'\N{GREEK CAPITAL LETTER DELTA}'):   u'delta_'}
    def cmdline_ui_loop(usercmd="", repl_delay=0.9):
        import time, re, textwrap
        exit_commands = ('q', 'quit', 'x', 'exit')
        help_commands = ('h', 'help', 'help()', '?')
        help_paren_parser = re.compile(r"help\s*\(\s*(.+)\s*\)")
        example = ("\n    Examples: chip.force_telemetry_on = True  # Forces the measurement system ON"
                   "\n                                              #   even when there's no VIN power."
                   "\n              chip.vcharge_jeita_2 = 4.05     # Set the per-cell charge voltage"
                   "\n                                              #   in JEITA region 2 to 4.05V."
                   "\n              chip.jeita_region               # Returns the current JEITA region."
                   "\n              chip.en_jeita = False           # Disables JEITA charging control"
                   "\n              chip.suspend_charger = True     # Forces the charger off"
                   "\n              chip.print_status()             # Show values of all bitfields on chip."
                   "\n        demoboard.read_smbalert()             # True only if /SMBALERT is active low."
                   "\n        demoboard.alert_response()            # Get SMBus address of device asserting"
                   "\n                                              #   /SMBALERT, if any."
                   "\n              help(thermistor_voltage)        # Explains the thermistor_voltage bitfield."
                   "\n    Or any of {} to end this program."
                   "\n: ").format(", ".join([repr(c) for c in exit_commands]))
        help_text = example
        twrap = textwrap.TextWrapper(width=79, replace_whitespace=False,
                                     initial_indent=' ', subsequent_indent='   ')
        while True:
            print "On {}, I read the following register values from the LTC4162:".format(time.asctime())
            data = dict(((chname, chip[chname]) for chname in dashboard_channel_names))
            if 'telemetry_valid' in data:
                if data['telemetry_valid']:
                    # Only read the telemetry channels if the IC reports telemetry_valid True.
                    data.update(((chname, chip[chname]) for chname in telemetry_channel_names))
                else:
                    print "  *** Not showing ADC readings because ADC/telemetry system isn't up yet."
                    print "  *** Try applying VIN or typing 'chip.force_telemetry_on = True'."
            print "\n".join("    {}: {}".format(chname, data[chname]) for chname in sorted(data))
            usercmd = raw_input("Press ENTER to refresh, or "
                                "type a Python expression/statement to execute: "
                                "{}".format(help_text))
            help_text = ""  # ... so we only show the help text the first time through the command loop,
                            #     for brevity.
            repl_reply = ""
            if usercmd.lower() in exit_commands:
                raise SystemExit
            elif usercmd == "":
                pass
            elif help_paren_parser.search(usercmd):
                # Handle request for help on a specific thing: "help(thing)".
                # Needed because a PyInstaller-created EXE doesn't support help().
                target_str = help_paren_parser.search(usercmd).groups()[0].strip()
                # Better UX for "help(chip.bitfield_name)":
                dotparts = [x.strip() for x in target_str.split('.')]
                if (target_str in type(chip).__dict__
                    and "fget" in dir(type(chip).__dict__[target_str])
                    and "fset" in dir(type(chip).__dict__[target_str])):
                    # thing is a property of the chip object, probably a bitfield/register
                    target_obj = type(chip).__dict__[target_str]
                elif (len(dotparts) == 2 and dotparts[0] == "chip"
                      and dotparts[1] in type(chip).__dict__
                      and "fget" in dir(type(chip).__dict__[dotparts[1]])
                      and "fset" in dir(type(chip).__dict__[dotparts[1]])):
                      # thing is "chip.foo", where foo is a property of the chip object,
                      # probably a bitfield/register
                      target_obj = type(chip).__dict__[dotparts[1]]
                else:
                    target_obj = None
                    try:
                        target_obj = eval(target_str, globals(), globals())
                    except SyntaxError:
                        repl_reply += "*** Help unavailable for '{}'\n".format(target_str)
                if hasattr(target_obj, "__doc__") and target_obj.__doc__:
                    repl_reply += "Help for {}:\n\n".format(target_str)
                    if isinstance(target_obj.__doc__, unicode):
                        repl_reply += \
                            target_obj.__doc__.translate(ascii_unicode_approx_table).encode("ascii")
                    elif isinstance(target_obj.__doc__, str):
                        repl_reply += target_obj.__doc__
                    else:
                        repl_reply += ("*** {}'s __doc__ isn't in any form I know how to display."
                                       "\n".format(target_str))
                else:
                    repl_reply += "*** No help found for '{}'.\n".format(target_str)
            elif usercmd.lower() in help_commands:
                help_text = example  # Show the help text again at the next prompt.
            else:
                try:
                    repl_reply += ("Evaluating {}:\n    {} == "
                                   "{}\n").format(repr(usercmd), usercmd,
                                               repr(eval(usercmd, globals(), globals())))
                except SyntaxError:
                    repl_reply += "Executing statement {}".format(repr(usercmd))
                    exec(usercmd, globals(), globals())
            #
            # All REPL printing happens here:
            #
            print
            for paragraph in repl_reply.splitlines():
                if paragraph == "":
                    print
                else:
                    for line in twrap.wrap(paragraph):
                        print line
            print
            #
            # Delay to allow the user to notice the REPL print:
            #
            if "***" in repl_reply:
                # An error of some sort happened. Prompt user before continuing.
                raw_input("\nPress ENTER to continue demo.")
            elif repl_reply:
                # We printed something. No errors happened.
                # Pause briefly to let the user notice the REPL output.
                time.sleep(repl_delay)
    #
    # Actual main program.
    #
    normal_exit_exceptions = (SystemExit, KeyboardInterrupt, EOFError)
    while True:
        try:
            cmdline_ui_loop()
        except i2c_error:
            print "*** I can talk to the demoboard, but I am getting i2c NACK/errors talking to the IC."
            print "    Is the IC getting power?"
        except PEC_error:
            print "*** Got corrupted i2c/SMBus response (Failed PEC/CRC)"
            print "    although framing and ACK/NACK bits seemed correct."
        except SerialTimeoutException:
            print "*** Timed out while trying to talk to the demoboard via USB/serial."
            print "*** Try re-connecting the demoboard's USB cable DIRECTLY to the computer"
            print "        WITHOUT going through any hubs."
            break
        except SerialException:
            print "*** Lost USB/serial connection"
            print "*** Try unplugging and re-plugging USB connections to demoboard."
            print "*** We strongly recommend connecting the board directly to a USB port on this computer"
            print "       without going through any hubs."
            break
        except normal_exit_exceptions:
            break
        except Exception as e:
            print "*** Caught exception {}".format(repr(type(e)))
            print "*** {}".format(e)
        raw_input("Press ENTER to continue demo / Ctrl-C to exit. ")
    last_exception_type, last_exception_value, last_traceback = sys.exc_info()
    if last_exception_type not in (None, ) + normal_exit_exceptions:
        raw_input("\nPress ENTER to quit.") # An abnormal exception occurred, let user read error message before
                                             # closing window (in the PyInstaller .EXE version of this script).
    else:
        pass  # Normal program termination, no need to wait.
