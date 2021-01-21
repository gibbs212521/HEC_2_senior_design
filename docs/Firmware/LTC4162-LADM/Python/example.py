"Python API usage example."

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

import LTC4162_LADM as LTC4162
from portable_labcomm_api import SMBus_Labcomm_interface

serial_port = 'COM16' #Modify this line as appropriate (for Linux, '/dev/ttyXX', etc)
demoboard = SMBus_Labcomm_interface(serial_port=serial_port, PEC=True)
LTC4162.LTC4162.ARA = lambda self: demoboard.alert_response()
LTC4162.LTC4162.SMBALERT = lambda self: demoboard.read_smbalert()
chip = LTC4162.LTC4162(read_function=demoboard.read_word, write_function=demoboard.write_word, verbose=False)

chip.print_status()