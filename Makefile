CC=gcc
CFLAGS=-c -Werror
LDFLAGS=
SOURCES=linked_list.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=linked_list

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

valgrind: $(EXECUTABLE)
	valgrind --leak-check=full --show-reachable=yes --show-possibly-lost=yes ./$(EXECUTABLE)
clean:
	rm $(EXECUTABLE) $(OBJECTS)
test: $(EXECUTABLE)
	./$(EXECUTABLE)
