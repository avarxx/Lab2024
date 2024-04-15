CC=gcc
CFLAGS=-c -Wall

DYNAMIC_SOURCES=$(wildcard Dynamic/*cpp)
LINKED_SOURCES=$(wildcard Linked/*cpp)

DYNAMIC_OBJECTS=$(patsubst %.cpp,%.o,$(DYNAMIC_SOURCES))
LINKED_OBJECTS=$(patsubst %.cpp,%.o,$(LINKED_SOURCES))

all: start

start: main.o $(DYNAMIC_OBJECTS) $(LINKED_OBJECTS)
	$(CC) $^ -o rezult.exe

Dynamic/%.o: Dynamic/%.cpp
	$(CC) $(CFLAGS) $< -o $@

Linked/%.o: Linked/%.cpp
	$(CC) $(CFLAGS) $< -o $@

main.o: main.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o rezult.exe
