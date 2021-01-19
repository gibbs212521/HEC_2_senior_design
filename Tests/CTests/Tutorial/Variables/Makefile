DIRPATH=..\..\..\..\bin\Tests\Tutorials
FILEPATH=$(DIRPATH)\test_variable.exe
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

MAKE: test_variable.o
  gcc test_variable.o -o $(FILEPATH)

test_variable.o: test_variable.c
  gcc -c test_variable.c -o test_variable.o

test_variable.c:
  set hashtag = ^#
  echo ^$(hashtag)include ^<stdio.h^> >> test_variable.c
  echo int main() > test_variable.c
  echo { >> test_variable.c
  echo int age; >> test_variable.c
  echo age = 29; >> test_variable.c
  echo printf("Bucky is %d years old\n", age); >> test_variable.c
  echo int new_age; >> test_variable.c
  echo printf("integer declaration and assignment successful\n"); >> test_variable.c
  echo new_age = 2021-1987; >> test_variable.c
  echo printf("Bucky is %d years old\n", new_age); >> test_variable.c
  echo printf("integer subtraction operation successful\n"); >> test_variable.c
  echo int var_age; >> test_variable.c
  echo int current_year; >> test_variable.c
  echo int birthYear; >> test_variable.c
  echo current_year = 2021; >> test_variable.c
  echo birthYear = 1963; >> test_variable.c
  echo var_age = current_year - birthYear; >> test_variable.c
  echo printf("Bucky is %d years old\n", var_age); >> test_variable.c
  echo printf("integer subtraction operation successful\n"); >> test_variable.c
  echo return 0; >> test_variable.c
  echo } >> test_variable.c

clean all:
  $(RM) test_variable.c
  $(RM) test_variable.o
  $(RM) $(FILEPATH)
