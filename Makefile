CC=c++
CFLAGS=-c -Wall -std=c++11
SOURCES=main.cpp randomPlayer.cpp humanPlayer.cpp player.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ttt

all: $(SOURCES) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm *.o ttt