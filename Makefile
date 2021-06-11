CC=gcc
CFLAGS=-g -Wall
TARGET=list
OBJS=find.o size.o swap.o remove.o between.o init_list.o empty_list.o main.o sort.o list.o

$(TARGET):	$(OBJS)
	$(CC) -o $@ $(OBJS)

init_list.o:	init_list.c
	$(CC) -c -o init_list.o init_list.c 

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

empty_list.o:	empty_list.c
	$(CC) -c -o empty_list.o empty_list.c

list.o:	list.c
	$(CC) -c -o list.o list.c

sort.o:	sort.c
	$(CC) -c -o sort.o sort.c

main.o:	main.c
	$(CC) -c -o main.o main.c

clean:
	rm $(OBJS) $(TARGET)
