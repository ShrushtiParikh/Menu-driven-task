$(CC) = gcc

final: main.o task_scheduler.o
	$(CC) main.o task_scheduler.o -o output

task_scheduler.o : task_scheduler.c task_scheduler.h
	$(CC) -c task_scheduler.c 

main.o: main.c task_scheduler.h
	$(CC) -c main.c