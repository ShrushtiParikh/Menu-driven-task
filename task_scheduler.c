#include <stdio.h>
#include <string.h>
#include "task_scheduler.h"
#define MAX_TASKS 100
int task_count = 0;
Task tasks[MAX_TASKS];

/**
 * @brief Adds a new task to the task scheduler.
 *
 * This function prompts the user for task details, such as description, due date, and priority,
 * and adds the task to the task list. If the task list is full (i.e., it has reached the maximum 
 * number of tasks), the function prints a message and exits without adding the task.
 *
 * The function also automatically assigns an ID to the new task based on the current task count
 * and saves the updated task list after adding the new task.
 * 
 * @note The function assumes that the global array `tasks[]` and the variable `task_count`
 *       are available and properly initialized. It also assumes the existence of `MAX_TASKS`
 *       which limits the number of tasks that can be added.
 *
 * @return void
 */
void add_task(){
    if(task_count >= MAX_TASKS)
    {
        printf("Tasks list is full\n");
        return;
    }

    Task new_task;
    new_task.id = task_count + 1;
    printf("Enter task description:");
    scanf(" %[^\n]",new_task.desc);
    printf("Enter due date(YYYY-MM_DD):");
    scanf("%s",new_task.due_date);
    printf("Enter priority (1 = low ,2 = Medium , 3 = High):");
    scanf("%d",&new_task.priority);
    tasks[task_count++] = new_task;
    printf("Task added sucessfully\n");
    save_tasks();
}

void list_tasks()
{
    if(task_count == 0)
    {
        printf("Task list is NULL\n");
    }

    printf("ID\tDescription\tDuedate\tPriority\t\n");
    printf("-----------------------------------\n");
    for(int i = 0 ; i < task_count ; i++)
    {
        printf("%d\t%s\t%s\t%d\n",tasks[i].id,tasks[i].desc,tasks[i].due_date,tasks[i].priority);
    }
}

void delete_task()
{
    int id;
    printf("Enter task ID to delete\n");
    scanf("%d",&id);
    int found = 0;
    for(int i = 0;i < task_count;i++)
    {
        if(tasks[i].id == id)
        {
            found = 1;
            for(int j = i;j < task_count - 1; j++)
            {
                tasks[j] = tasks[j+i];
            }
            task_count--;
            printf("Task deleted successfully\n");
            break;
        }
    }

    if(!found)
    {
        printf("Task with ID %d not found\n",id);
    }
}

void sort_tasks(sort_func compare)
{
    if(task_count == 0)
    {
        printf("Task list is NULL\n");
        return 0;
    }
    for(int i = 0 ; i < task_count-1 ; i ++)
    {
        for(int j = 0 ; i < task_count - i - 1 ; j ++)
        {
            if(compare(tasks[j],tasks[j + 1]) > 0)
            {
                Task temp = tasks[j];
                tasks[j] = tasks[j+1];
                tasks[j+1] = temp;
            }
        }
    }
    printf("Tasks sorted successfully!\n");
}

void save_tasks()
{
    FILE *fp = fopen("tasks.txt","a");
    if(fp != NULL)
    {
        printf("Adding data to file\n");
        for(int i = 0 ; i < task_count ; i++)
        {
            fprintf(fp,"%d\t%s\t%s\t%d\n",tasks[i].id,tasks[i].desc,tasks[i].due_date,tasks[i].priority);
        }
    }
    else
    {
        printf("Error opening file\n");
    }
}

int compare_by_priority(Task t1,Task t2)
{
    if(t1.priority == t2.priority)
    {
        printf("Both Tasks have same priority\n");
        return;
    }
    return t1.priority = t2.priority;
}

int compare_by_due_date(Task t1,Task t2)
{
    if(strcmp(t1.due_date,t2.due_date) == 0)
    {
        printf("Both Tasks are due on same date\n");
        return;
    }
    return strcmp(t1.due_date,t2.due_date);
}