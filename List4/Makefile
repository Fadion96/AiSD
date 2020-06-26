CC = g++
VPATH=header


.PHONY: clean

all: clean tree treestats

tree: Tree.h Node.h
		$(CC) -o tree tree_ex.cpp Tree.cpp Node.cpp

treestats: Tree.h Node.h
		$(CC) -o tree_stats tree_stats.cpp Tree.cpp Node.cpp

clean:
		rm -f *.o tree tree_stats tree_stats.txt