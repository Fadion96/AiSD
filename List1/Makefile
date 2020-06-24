CC = gcc

.PHONY: clean

all: clean fifo linkedlist doublylinkedlist

fifo:
		$(CC) fifo.c -o fifo 

linkedlist:
		$(CC) singlyLinkedList.c -o linkedlist

doublylinkedlist:
		$(CC) circularDoublyLinkedList.c -o doublylinkedlist

clean:
		rm -f *.o fifo linkedlist doublylinkedlist