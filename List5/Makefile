CC = g++
VPATH=header


.PHONY: clean

all: clean lcs ed ostree ostreestats

lcs: 
		$(CC) -o lcs lcs.cpp 

ed:
		$(CC) -o ed editDistance.cpp 

ostree: Tree.h Node.h
		$(CC) -o ostree OSTree.cpp Tree.cpp Node.cpp

ostreestats: Tree.h Node.h
		$(CC) -o ostree_stats OSTree_stats.cpp Tree.cpp Node.cpp

clean:
		rm -f *.o lcs ed ostree ostreestats tree_os_stat.txt