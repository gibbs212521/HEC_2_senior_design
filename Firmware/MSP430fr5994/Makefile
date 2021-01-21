DIRPATH=..\..\..\..\bin\MSP430
FILENAME1=msp430
FILEPATH1=$(DIRPATH)\$(FILENAME1).exe
CC=gcc
CL \L /IC:\ti\ccs1011\ccs\ccs_base\msp430\include #-IC:/ti/ccs1011/ccs/tools/compiler/ti-cgt-msp430_20.2.4.LTS/include

# Code below should allow nmake and make to operate successfully
# NMAKE code here \
!ifndef 0 # \  
MV=move # \
RM=del # \
CP=copy # \
!else
# Make code here 
MV=mv -f # 
RM=rm -f # 
CP=cp -f # 
# 
!endif

MAKE: $(FILENAME1).o
  $(CC) $(FILENAME1).o -o $(FILEPATH1)

$(FILENAME1).o: $(FILENAME1).c
  $(CC) -c $(FILENAME1).c -o $(FILENAME1).o


clean:
  $(RM) $(FILENAME1).o
  $(RM) $(FILEPATH1)
