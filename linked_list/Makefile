CC=gcc
CFLAGS=-c -Werror -ggdb
LDFLAGS=
SOURCES=linked_list.c main.c
INCLUDES=linked_list.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=linked_list

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

valgrind: $(EXECUTABLE)
	valgrind --leak-check=full --show-reachable=yes --show-possibly-lost=yes ./$(EXECUTABLE)
clean:
	rm $(EXECUTABLE) $(OBJECTS)
test: $(EXECUTABLE)
	./$(EXECUTABLE)
