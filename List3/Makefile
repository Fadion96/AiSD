CC = gcc
VPATH=header


.PHONY: clean

all: clean radix select randselect selects_stats quickselect

radix: 
		$(CC) -o radix radix.c -lm
run:
		./radix
	
select:
		$(CC) -o select select.c 

randselect:
		$(CC) -o randselect randselect.c 

selects_stats:
		$(CC) -o selects_stats selects_stats.c

quickselect:
		$(CC) -o quickselect quickselect.c

clean:
		rm -f *.o radix select randselect selects_stats quickselect *.txt