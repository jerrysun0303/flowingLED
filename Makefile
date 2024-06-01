# Makefile for compiling flowingLed.c into flowingLed executable  

CC = gcc
CFLAGS = -Wall
TARGET = flowingLed

all: $(TARGET)

$(TARGET): flowingLed.c
	$(CC) $(CFLAGS) -o $(TARGET) flowingLed.c

clean:
	rm -f $(TARGET)
