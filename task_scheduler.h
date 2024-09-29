typedef struct{
    int id;
    char desc[100];
    char due_date[11];
    int priority; 
}Task;

#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

//typedef for a func pointer that compares two tasks
typedef int (*sort_func)(Task,Task);

//Function prototypes
void add_task();
void list_tasks();
void delete_task();
void sort_tasks(sort_func compare);
void save_tasks();

//Sorting comparision functions
int compare_by_priority(Task t1,Task t2);
int compare_by_due_date(Task t1,Task t2);
#endif

