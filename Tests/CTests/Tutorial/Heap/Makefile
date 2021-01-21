DIRPATH=..\..\..\..\bin\Tests\Tutorials
FILENAME1=test_heap
FILEPATH1=$(DIRPATH)\$(FILENAME1).exe
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
  $(CC) $(FILENAME1).o -o $(FILEPATH1)

$(FILENAME1).o: $(FILENAME1).c
  $(CC) -c $(FILENAME1).c -o $(FILENAME1).o


clean:
  $(RM) $(FILENAME1).o
  $(RM) $(FILEPATH1)
