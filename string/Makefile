CC=gcc
CFLAGS=-c -Werror -ggdb
LDFLAGS=
SOURCES=string_practice.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=string_pr

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
