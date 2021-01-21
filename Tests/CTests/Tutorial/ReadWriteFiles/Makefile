DIRPATH=..\..\..\..\bin\Tests\Tutorials
FILENAME1=test_write_file
FILENAME2=test_read_file
FILENAME3=test_append_file
FILEPATH1=$(DIRPATH)\$(FILENAME1).exe
FILEPATH2=$(DIRPATH)\$(FILENAME2).exe
FILEPATH3=$(DIRPATH)\$(FILENAME3).exe
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

MAKE: $(FILENAME1).o $(FILENAME2).o $(FILENAME3).o
  $(CC) $(FILENAME1).o -o $(FILEPATH1)
  $(CC) $(FILENAME2).o -o $(FILEPATH2)
  $(CC) $(FILENAME3).o -o $(FILEPATH3)


$(FILENAME1).o: $(FILENAME1).c
  $(CC) -c $(FILENAME1).c -o $(FILENAME1).o

$(FILENAME2).o: $(FILENAME2).c
  $(CC) -c $(FILENAME2).c -o $(FILENAME2).o

$(FILENAME3).o: $(FILENAME3).c
  $(CC) -c $(FILENAME3).c -o $(FILENAME3).o


clean:
  $(RM) $(FILENAME1).o
  $(RM) $(FILENAME2).o
  $(RM) $(FILENAME3).o
  $(RM) $(FILEPATH1)
  $(RM) $(FILEPATH2)
  $(RM) $(FILEPATH3)
  $(RM) bacon.txt
