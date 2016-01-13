CC=c++
CFLAGS=-c -Wall -std=c++11 -g
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ttt
SOURCES=main.cpp \
        randomPlayer.cpp \
        humanPlayer.cpp \
        minimaxPlayer.cpp \
        player.cpp

all: $(SOURCES) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm *.o ttt
