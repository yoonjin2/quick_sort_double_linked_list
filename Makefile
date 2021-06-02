CC=gcc
CFLAGS=-g -Wall
TARGET=queue
OBJS=find.o size.o swap.o remove.o between.o init_queue.o empty_queue.o main.o sort.o queue.o

$(TARGET):	$(OBJS)
	$(CC) -o $@ $(OBJS)

init_queue.o:	init_queue.c
	$(CC) -c -o init_queue.o init_queue.c 

swap.o:	swap.c
	$(CC) -c -o swap.o swap.c

find.o:	find.c
	$(CC) -c -o find.o find.c

size.o:	size.c
	$(CC) -c -o size.o size.c

remove.o: remove.c
	$(CC) -c -o remove.o remove.c

between.o:	between.c
	$(CC) -c -o between.o between.c

empty_queue.o:	empty_queue.c
	$(CC) -c -o empty_queue.o empty_queue.c

queue.o:	queue.c
	$(CC) -c -o queue.o queue.c

sort.o:	sort.c
	$(CC) -c -o sort.o sort.c

main.o:	main.c
	$(CC) -c -o main.o main.c

clean:
	rm $(OBJS) $(TARGET)
