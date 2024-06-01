# Makefile for compiling flowingLed.c into flowingLed executable  
TARGET = flowingLed

all: $(TARGET)

$(TARGET): flowingLed.c
	$(CC) -o $(TARGET) flowingLed.c

clean:
	rm -f $(TARGET)
