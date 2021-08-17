CC=gcc
CFLAGS=-g -Wall -ansi
OBJS=obj/main.o
TARGET=run
LDLIBS=-lm

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)
	
obj/main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f obj/*.o $(TARGET)