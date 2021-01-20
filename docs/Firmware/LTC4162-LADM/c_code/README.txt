
LTC4162 C Library
==============================

Introduction:
-------------

This  C library includes headers and several functions to simplify communication
with  the  LTC4162.  This  low  level library provides a header file with the
definitions  of registers and bit fields within those registers, and routines to
read and write those registers and individual bit-fields.

Files:
------

LTC4162-LADM_reg_defs.h - Header file containing definitions of registers and bit
fields in the LTC4162.  Names and addresses of registers are defined here.
Names, addresses, sizes, offsets, and masks are defined for bit fields in the
LTC4162.  This information is also packed into a definition that is used by
LTC4162-LADM.c

LTC4162-LADM.c - Functions to initialize a LTC4162 instance, read and write
registers and bit-fields

LTC4162-LADM.h - Header file defining prototypes, data structures and constants
used by LTC4162-LADM.c

LTC4162-LADM_formats.h - File defining constants and macros that can be used by
LTC4162-LADM.c to convert real values to LTC4162 integer values at compile-time
(optimized away) and to convert LTC4162 integer values to real values at run-time
for UI display or debug (floating point arithmetic required).

LTC4162-LADM_pec.c - File containing bit-wise and table lookup CRC-8 functions to
compute SMBus Packet Error Check byte.

LTC4162-LADM_pec.h - File containing Packet Error Check function headers.

LTC4162-LADM_example_generic.c - An example showing how to use the LTC4162.c
library. Dummy functions containing print statements are used in place of
hardware reads and writes.

LTC4162-LADM_example_linux.c - An example using the Linux kernel i2c-dev
interface to communicate with the LTC4162. We've tested this
on a Raspberry Pi 3 Model B.

LTC4162-LADM_bf_config.c - An example re-writing all LTC4162 writable
bit fields to their power-on default state. Can be used as a template to
quickly modify settings from their default.

LTC4162-LADM_reg_config.c - An example re-writing all LTC4162 writable
registers to their power-on default state. Can be used as a template to
quickly modify settings from their default. This program is smaller, but
less readable than LTC4162-LADM_bf_config.c.

LTC4162-LADM_example_mzero.ino - An Arduino Zero compatible example using
the libraries within MZeroSketchbook to communicate with the LTC4162.
This example can be uploaded directly to the DC2038A demoboard. The default GUI-
compatible DC2038A firmware can be restored through the DC2038A GUI.
To build the Arduino Zero project successfully, the following common files
must be in the LTC4162-LADM_example_mzero folder:
  LTC4162-LADM_example_mzero.ino (exists in folder by default)
  LTC4162-LADM.c
  LTC4162-LADM.h
  LTC4162-LADM_formats.h
  LTC4162-LADM_reg_defs.h
Install Arduino IDE version 1.8.7 or later from https://www.arduino.cc/en/Main/Software
if you don't already have it. In Windows Explorer, double-click on the copy of
LTC4162-LADM_example_mzero.ino to launch Arduino IDE.
Click on Tools -> Board: -> Boards Manager , and install the
"Arduino SAMD Boards" version 1.6.20 or later.
Click on Tools -> Board: and select Arduino/Genuino Zero (Native USB Port).
Click on File -> Preferences , and change Sketchbook location to be the path to
the MZeroSketchbook folder. This is located at the top-level directory of this SDK.
Plug in your LTC4162-LADM demoboard via USB.
Click on Tools -> Port . Select the port corresponding to the LTC4162-LADM demoboard.
You're now ready to compile and upload the sketch to your LTC4162-LADM demoboard.

LTC4162-LADM_example_linduino.ino - An example using the LT_SMBus Linduino library
to communicate with the LTC4162. This example can be uploaded onto a Linduino and
can also be easily adapted to use other TWI/I2C/SMBus Arduino libraries.
More information about Linduino is available here:
https://www.analog.com/en/design-center/evaluation-hardware-and-software/linduino.html
To build the Linduino project successfully, the following common files
must be in the LTC4162-LADM_example_linduino folder:
  LTC4162-LADM_example_linduino.ino
  LTC4162-LADM.c
  LTC4162-LADM.h
  LTC4162-LADM_formats.h
  LTC4162-LADM_reg_defs.h
Install Arduino IDE version 1.8.7 or later from https://www.arduino.cc/en/Main/Software
if you don't already have it. In Windows Explorer, double-click on the copy of
LTC4162-LADM_example_ linduino.ino to launch Arduino IDE.
Click on Tools -> Board: and select Arduino/Genuino Uno.
Click on File -> Preferences , and change Sketchbook location to be the path to
the LTSketchbook folder which can be downloaded from here:
https://github.com/analogdevicesinc/Linduino/tree/master/LTSketchbook
Plug in your Linduino via USB.
Click on Tools -> Port . Select the port corresponding to the Linduino.
You're now ready to compile and upload the sketch to your Linduino.

Makefile - Makefile to build the examples.  Targets are generic, linux and clean.
  "make generic" builds LTC4162-LADM_example_generic.c.
  "make linux" builds LTC4162-LADM_example_linux.c.
