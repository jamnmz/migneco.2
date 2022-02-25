#Jared Migneco cs4760 proj2 makefile
CC = gcc
CFLAGS = -g

all: master.c slave.c

master: master.c
        gcc -o master master.c
slave: slave.c
        gcc -o slave slave.c

clean:
        -rm *.o $(objects)
