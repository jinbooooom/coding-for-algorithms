OBJS = bubble.o insert.o merge.o quick.o select.o shell.o sort.o
#OBJS = $(wildcard *.o)
SRC = $(wildcard *.cpp)

CC = g++
STD = -std=c++11

sort:${OBJS}
	${CC} ${OBJS} -o $@ ${STD}
all:${SRC}
	${CC} -c ${SRC} ${STD}
clean:
	rm -f *.o sort
