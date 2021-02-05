DIRPATH=..\..\..\..\bin\Tests\Tutorials
FILENAME1=test_oop
FILEPATH1=$(DIRPATH)\$(FILENAME1).exe
INCL=..\..\..\..\Firmware\MSP430fr5994_MCU\Includes
OBJ1PATH=..\..\..\..\Firmware\MSP430fr5994_MCU\util\Scheduler
OBJ1NAME=scheduler
OBJ1=$(OBJ1PATH)\$(OBJ1NAME)
CC=gcc
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
  $(CC) $(FILENAME1).o $(OBJ1NAME).o  -o $(FILEPATH1)
  $(RM) $(OBJ1NAME).o
  $(RM) $(FILENAME1).o

$(FILENAME1).o: $(FILENAME1).c
  $(CC) -c $(OBJ1).c -I $(INCL) -o $(OBJ1NAME).o
  $(CC) -c $(FILENAME1).c -o $(FILENAME1).o

clean:
  $(RM) $(OBJ1NAME).o
  $(RM) $(FILENAME1).o
  $(RM) $(FILEPATH1)
