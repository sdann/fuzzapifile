CC = afl-gcc
CFLAGS = -g -Wall

TARGET = libfuzzapifile
SRCS = parse.c sysc.c argfd.c
OBJS = parse.o sysc.o argfd.o

all: $(TARGET).a

$(TARGET).a: $(OBJS)
	ar rcs $@ $^

argfd.o: argfd.c
	$(CC) -c -o $@ $<

sysc.o: sysc.c
	$(CC) -c -o $@ $<

parse.o: parse.c
	$(CC) -c -o $@ $<

clean:
	rm -f *.o *.a
