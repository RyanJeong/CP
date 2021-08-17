CC=gcc
CFLAGS=-g -Wall -ansi
OBJS=obj/main.o
TARGET=run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	
obj/main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f obj/*.o $(TARGET)