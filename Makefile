CC=g++
CFLAGS=-o
CVERSION=c++11

$1: $1.cpp
	$(CC) -Wall -std=$(CVERSION) $(CFLAGS) cpp/$1 cpp/$1.cpp
