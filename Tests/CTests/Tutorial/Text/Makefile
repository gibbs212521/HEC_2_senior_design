DIRPATH=..\..\..\..\bin\Tests\Tutorials
FILEPATH=$(DIRPATH)\test_text.exe
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

MAKE: test_text.o
  gcc test_text.o -o $(FILEPATH)

test_text.o: test_text.c
  gcc -c test_text.c -o test_text.o

test_text.c:
  echo int main() > test_text.c
  echo { >> test_text.c
  echo printf("Hello World!"); >> test_text.c
  echo printf("\nEnd Line Enacted \n\n"); >> test_text.c
  echo printf("Audio Beep Enacted \a \n"); >> test_text.c
  echo printf("Tabular Shift 'Tab' Enacted \t see \t these \t tabs \n"); >> test_text.c
  echo printf("%%s is a test for substitution %%s\n", "THIS", "HERE"); >> test_text.c
  echo printf("String replacement successful.\n"); >> test_text.c
  echo printf("I ate %%d corndogs last night... Thanks %%s\n", 25, "Bucky"); >> test_text.c
  echo printf("Integer, decimal replacement successful.\n"); >> test_text.c
  echo printf("Pi is %%f\n", 3.1415926535); >> test_text.c
  echo printf("%%d decimal places shown in float replacement\n", 6); >> test_text.c
  echo printf("Pi is %%.7f\n", 3.1415926535); >> test_text.c
  echo printf("%%d decimal places shown in float replacement\n", 7); >> test_text.c
  echo printf("Pi is %%.4f\n", 3.1415926535); >> test_text.c
  echo printf("%%d decimal places shown in float replacement\n", 4); >> test_text.c
  echo char some_name[14] = "Bucky Roberts"; >> test_text.c
  echo printf("The first letter of some name is %%c\n", some_name[0]); >> test_text.c
  echo printf("The Third letter of some name is %%c\n", some_name[2]); >> test_text.c
  echo printf("Some name is %%s \n", some_name); >> test_text.c
  echo some_name[2] = 'z'; >> test_text.c
  echo printf("The third letter has changed, see %%s\n", some_name); >> test_text.c
  echo printf("The Third letter of some name has changed to %%c\n", some_name[2]); >> test_text.c
  echo char food[] = "tuna"; >> test_text.c
  echo printf("This is the best food ever, %%s.  It was assigned without defining its array size btw.\n", food); >> test_text.c
  echo strcpy(food, "BACON!"); >> test_text.c
  echo printf("This is the best food ever, %%s.  It was assigned with the string copy (strcpy) command.\n", food); >> test_text.c
  echo return 0; >> test_text.c
  echo } >> test_text.c

clean all:
  $(RM) test_text.c
  $(RM) test_text.o
  $(RM) $(FILEPATH)
