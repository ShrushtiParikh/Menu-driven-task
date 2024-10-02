# Menu-Driven Task Scheduler

## Project Description

In this project, I learnt how to create a Menu-Driven Task Scheduler in C using function pointers.

A functional task scheduler where you can:
- Add tasks with descriptions, due dates, and priorities.
- View a list of tasks.
- Delete tasks by their ID.
- Persist data across program runs by saving tasks to a file.

## File Structure

. ├── Makefile ├── main.c ├── task_scheduler.c └── task_scheduler.h


### Files Overview

- **task_scheduler.h**: Header file containing the definitions of task structure, function prototypes, and constants.
- **task_scheduler.c**: Implementation file containing the functions for managing tasks (adding, deleting, viewing, sorting).
- **main.c**: The entry point of the application, containing the menu and user interface.
- **Makefile**: Script for compiling the project.

## Features

1. **Task Management**
   - Add new tasks with descriptions, due dates, and priorities.
   - View all tasks stored in memory or in the file.
   - Delete specific tasks by their ID.

2. **Data Persistence**
   - Tasks are stored in a file, ensuring that data is retained even after the program is closed and reopened.

3. **Dynamic Task Sorting**
   - Tasks can be dynamically sorted based on priority or due date using function pointers for flexibility.

## Usage Instructions

1. **Compile the Project**
   Use the Makefile to compile the project. Run the following command in the terminal:
   ```bash
   make

    Run the Program After compiling, run the program using:

    bash

    ./output

    Menu Navigation Follow the on-screen instructions to add, view, delete, or sort tasks.


## To-Do List

- Supporting categories or labels for tasks.
- File Management The tasks are automatically saved to a file when added or deleted. Upon restarting the program, the previous data will be loaded.
- Implementing search function by description and date.
- Error handling mechanisms.