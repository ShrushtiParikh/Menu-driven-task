#include <stdio.h>
#include "task_scheduler.h"

void display_menu()
{
    printf("Task scheduler menu:\n");
    printf("1. Add Task\n");
    printf("2. List Tasks\n");
    printf("3. Delete Task\n");
    printf("4. Sort Tasks by Priority\n");
    printf("5. Sort Tasks by Due Date\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    int choice;
    while(1)
    {
        display_menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                add_task();
            break;
            case 2:
                list_tasks();
            break;
            case 3:
                delete_task();
            break;
            case 4:
                sort_tasks(compare_by_priority);
                list_tasks();
            break;
            case 5:
                sort_tasks(compare_by_due_date);
                list_tasks();
            break;
            case 6:
                printf("Exiting task scheduler\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }            
    }
    return 0;
}