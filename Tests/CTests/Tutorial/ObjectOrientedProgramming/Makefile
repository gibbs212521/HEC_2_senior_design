DIRPATH=..\..\..\..\bin\Tests\Tutorials
BINPATH=..\..\..\..\bin\MSP430
FILENAME1=test_oop
FILEBIN1=$(BINPATH)\$(FILENAME1).o
FILEPATH1=$(DIRPATH)\$(FILENAME1).exe

INCL=..\..\..\..\Firmware\MSP430fr5994_MCU\Includes

OBJ1PATH=..\..\..\..\Firmware\MSP430fr5994_MCU\util\Scheduler
OBJ1NAME=scheduler
OBJ1BIN=$(BINPATH)\$(OBJ1NAME).o
OBJ1=$(OBJ1PATH)\$(OBJ1NAME)

OBJ2PATH= ..\..\..\..\Firmware\MSP430fr5994_MCU\util\Bluetooth
OBJ2NAME=bluetooth_task
OBJ2BIN=$(BINPATH)\$(OBJ2NAME).o
OBJ2=$(OBJ2PATH)\$(OBJ2NAME)
OBJ2ANAME=bluetooth_init
OBJ2ABIN=$(BINPATH)\$(OBJ2ANAME).o
OBJ2A=$(OBJ2PATH)\$(OBJ2ANAME)
OBJ2BNAME=bluetooth_conn
OBJ2BBIN=$(BINPATH)\$(OBJ2BNAME).o
OBJ2B=$(OBJ2PATH)\$(OBJ2BNAME)
OBJ2CNAME=bluetooth_trans
OBJ2CBIN=$(BINPATH)\$(OBJ2CNAME).o
OBJ2C=$(OBJ2PATH)\$(OBJ2CNAME)

OBJ3PATH=..\..\..\..\Firmware\MSP430fr5994_MCU\util\Ticker
OBJ3NAME=lcd_task
OBJ3BIN=$(BINPATH)\$(OBJ3NAME).o
OBJ3=$(OBJ3PATH)\$(OBJ3NAME)

OBJ4PATH=..\..\..\..\Firmware\MSP430fr5994_MCU\util\Comm
OBJ4NAME=comm_protocol
OBJ4BIN=$(BINPATH)\$(OBJ4NAME).o
OBJ4=$(OBJ4PATH)\$(OBJ4NAME)

OBJ5PATH=..\..\..\..\Firmware\MSP430fr5994_MCU\util\Power
OBJ5NAME=power_task
OBJ5BIN=$(BINPATH)\$(OBJ5NAME).o
OBJ5=$(OBJ5PATH)\$(OBJ5NAME)

CC=gcc
CFLAGS= -I $(INCL)
SOURCES= $(OBJ1).c $(OBJ2).c $(OBJ2A).c $(OBJ2B).c $(OBJ2C).c $(OBJ3).c  $(OBJ4).c  $(OBJ5).c 
HEADERS= $(OBJ1).h $(OBJ2).h $(OBJ2A).h $(OBJ2B).h $(OBJ2C).h $(OBJ3).h  $(OBJ4).h  $(OBJ5).h 
OBJECTS= $(OBJ1BIN) $(OBJ2BIN) $(OBJ2ABIN) $(OBJ2BBIN) $(OBJ2CBIN) $(OBJ3BIN) $(OBJ4BIN) \
  $(OBJ5BIN)
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

# .PHONY : all
# all : $(FILEPATH1)

# $(FILEPATH1) : $(FILENAME1).o
MAKE : $(FILEBIN1) $(OBJECTS)
  $(CC) $(CFLAGS) $(FILEBIN1) $(OBJECTS) -o $(FILEPATH1)

$(FILEBIN1): $(FILENAME1).c
  $(CC) $(CFLAGS) -c $(FILENAME1).c -o $(FILEBIN1)
  $(CC) -c $(OBJ1).c -I $(INCL) -o $(OBJ1BIN)
  $(CC) -c $(OBJ2).c -I $(INCL) -o $(OBJ2BIN)
  $(CC) -c $(OBJ2A).c -I $(INCL) -o $(OBJ2ABIN)
  $(CC) -c $(OBJ2B).c -I $(INCL) -o $(OBJ2BBIN)
  $(CC) -c $(OBJ2C).c -I $(INCL) -o $(OBJ2CBIN)
  $(CC) -c $(OBJ3).c -I $(INCL) -o $(OBJ3BIN)
  $(CC) -c $(OBJ4).c -I $(INCL) -o $(OBJ4BIN)
  $(CC) -c $(OBJ5).c -I $(INCL) -o $(OBJ5BIN)


clean : 
  $(RM) $(FILEBIN1) $(OBJECTS) $(FILEPATH1)
