CC=g++
CFLAGS=-c -Werror -ggdb -std=c++11
LDFLAGS=
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=stack_problems

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
