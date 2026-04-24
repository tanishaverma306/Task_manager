Task Manager in C
Overview
This project is a Task Manager application developed in C using a singly linked list. It enables efficient task management through dynamic memory allocation, providing flexibility compared to array-based implementations.
Each task includes the following attributes:
ID
Title
Priority (High, Medium, Low)
Completion Status (Pending or Completed)
Features
Add new tasks
Display all tasks
Mark tasks as completed
Delete tasks
View pending tasks
Menu-driven interface for user interaction
Concepts Used
Singly Linked List
Dynamic Memory Allocation (malloc, free)
Pointer Manipulation
Structures in C
Menu-driven programming
How to Run
Compile the program
gcc task_manager.c -o task_manager
Run the program
./task_manager
On Windows systems:
task_manager.exe
File Structure
task_manager.c   # Main source code  
README.md        # Project documentation  
Future Improvements
Add search functionality by ID or title
Enable updating task details
Implement file handling to store tasks persistently
Add sorting based on priority
Learning Outcome
This project demonstrates the practical use of linked lists in application development. It strengthens understanding of dynamic memory allocation, data structures, and efficient data management in C.
