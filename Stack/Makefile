#CC указывает компилятор, используемый для сборки
CC=gcc
#в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS=-c -Wall

all: start

start: main.o dynamicArray.o singlyLinked.o testDynamicArray.o testLinked.o
	$(CC) main.o dynamicArray.o singlyLinked.o testDynamicArray.o testLinked.o -o rezult.exe

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

dynamicArray.o: dynamicArray.cpp
	$(CC) $(CFLAGS) dynamicArray.cpp


singlyLinked.o: singlyLinked.cpp
	$(CC) $(CFLAGS) singlyLinked.cpp


testDynamicArray.o: testDynamicArray.cpp
	$(CC) $(CFLAGS) testDynamicArray.cpp


testLinked.o: testLinked.cpp
	$(CC) $(CFLAGS) testLinked.cpp

clean:
	rm -rf *.o start