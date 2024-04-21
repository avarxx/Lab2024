CC=gcc
CFLAGS=-c -Wall

DYNAMIC_SOURCES=$(wildcard Dynamic/*.c)
LINKED_SOURCES=$(wildcard Linked/*.c)

DYNAMIC_OBJECTS=$(patsubst %.c,%.o,$(DYNAMIC_SOURCES))
LINKED_OBJECTS=$(patsubst %.c,%.o,$(LINKED_SOURCES))

all: start

start: main.o $(DYNAMIC_OBJECTS) $(LINKED_OBJECTS)
	$(CC) $^ -o rezult.exe

Dynamic/%.o: Dynamic/%.c
	$(CC) $(CFLAGS) $< -o $@

Linked/%.o: Linked/%.c
	$(CC) $(CFLAGS) $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o rezult.exe
