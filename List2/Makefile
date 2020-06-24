CC = gcc
VPATH=header


.PHONY: clean

all: clean insert merge quick mergeinsert quickinsert dualpivotquick

insert: ./header/sorts.h
		$(CC) -o insert insert.c ./header/sorts.c


merge: ./header/sorts.h
		$(CC) -o merge merge.c ./header/sorts.c


quick: ./header/sorts.h
		$(CC) -o quick quick.c ./header/sorts.c

mergeinsert: ./header/sorts.h
		$(CC) -o mergeinsert mergeinsert.c ./header/sorts.c

quickinsert: ./header/sorts.h
		$(CC) -o quickinsert quickinsert.c ./header/sorts.c

dualpivotquick: ./header/sorts.h
		$(CC) -o dualpivotquick dualpivotquick.c ./header/sorts.c

run:
	./insert
	./merge
	./quick
	./mergeinsert
	./quickinsert
	./dualpivotquick
	
clean:
		rm -f *.o insert quick merge mergeinsert quickinsert dualpivotquick *.txt