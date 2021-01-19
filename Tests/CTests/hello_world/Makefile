RM=del \Q
DIRPATH=..\..\..\bin\Tests\CTests
FILEPATH=$(DIRPATH)\test_hello_world.exe

MAKE: test_hello_world.o
  gcc test_hello_world.o -o $(FILEPATH)

test_hello_world.o: test_hello_world.c
  gcc -c test_hello_world.c -o test_hello_world.o

test_hello_world.c:
  echo int main() > test_hello_world.c
  echo { >> test_hello_world.c
  echo printf("Hello World!"); >> test_hello_world.c
  echo return 0; >> test_hello_world.c
  echo } >> test_hello_world.c

clean all:

  $(RM) test_hello_world.c
  $(RM) test_hello_world.o
  $(RM) $(FILEPATH)
