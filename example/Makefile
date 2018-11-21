CC = afl-gcc
DBGFLAGS = -Og -g -DENABLE_DEBUG
CFLAGS =  -I ../
LDFLAGS = -L ../

SRCS = target.c

all: debug
	${CC} ${SRCS} -o target -lfuzzapifile ${CFLAGS} ${LDFLAGS}

debug:
	${CC} ${SRCS} ${DBGFLAGS} -o target-debug -lfuzzapifile ${CFLAGS} ${LDFLAGS}

clean:
	rm target target-debug
