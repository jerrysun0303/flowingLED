# Makefile for compiling flowingled.c to flowingled executable 
TARGET = flowingled 

all: $(TARGET) 

$(TARGET): flowingled.c 
	$(CC) -o $(TARGET) flowingled.c 

clean: 
	rm -f $(TARGET)
