CC=g++
PGI=pgc++
CVERSION=-std=c++14
CFLAGS=-lGL -lGLU -lglut -fopenmp -lX11
PFLAGS=-lGL -lGLU -lglut
OUTPUT=main
INPUT=cun_acc.cpp
PGIFLAG=-acc -ta=tesla:cc60 -Minfo=accel

all:
	$(CC) $(CVERSION) -o $(OUTPUT) $(INPUT) $(CFLAGS)

pgi:
	$(PGI) $(CVERSION) $(PGIFLAG) -o $(OUTPUT) $(INPUT) $(PFLAGS)
	