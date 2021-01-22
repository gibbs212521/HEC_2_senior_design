DIRPATH=..\..\bin\MSP430
FILENAME1=msp430_proj
FILEPATH1=$(DIRPATH)\$(FILENAME1).exe
CC=gcc
include_1 = .\includes
# NOTE For INCLUDES : place -I$(dir) for every directory that needs to be included
#                 AND be sure to include a subst cmd for each include_#.
#
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
DIRPATH:=$(subst '\','/',$(DIRPATH) ) #
FILEPATH1:=$(subst '\','/',$(FILEPATH1) ) #
FILEPATH1:=$(subst '.exe','',$(FILEPATH1) ) #
include_1:=$(subst '\','/',$(include_1) ) #
# 
!endif
INCLUDES = -I$(include_1)

MAKE: $(FILENAME1).o
  $(CC) $(FILENAME1).o -o $(FILEPATH1)

$(FILENAME1).o: $(FILENAME1).c
  $(CC) -c $(INCLUDES) $(FILENAME1).c -o $(FILENAME1).o

clean:
  $(RM) $(FILENAME1).o
  $(RM) $(FILEPATH1)
