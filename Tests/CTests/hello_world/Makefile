MAKE: test_hello_world.o
  EXEFILEPATH = ..\..\..\bin\Tests\CTests
  gcc test_hello_world.o -o $(EXEFILEPATH)test_hello_world.exe

test_hello_world.o: test_hello_world.c
  gcc -c test_hello_world.c -o test_hello_world.o

test_hello_world.c:
  echo int main() > test_hello_world.c
  echo { >> test_hello_world.c
  echo printf("Hello World!"); >> test_hello_world.c
  echo return 0; >> test_hello_world.c
  echo } >> test_hello_world.c

