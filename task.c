#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Task
struct Task {
    int id;
    char title[100];
    int priority;
    int completed; // 0 = pending, 1 = done
    struct Task* next;
};

struct Task* head = NULL;

// Function to create a new task
struct Task* createTask(int id, char title[], int priority) {
    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
    newTask->id = id;
    strcpy(newTask->title, title);
    newTask->priority = priority;
    newTask->completed = 0;
    newTask->next = NULL;
    return newTask;
}

// Add Task
void addTask() {
    int id, priority;
    char title[100];

    printf("Enter Task ID: ");
    scanf("%d", &id);
    getchar(); // clear buffer

    printf("Enter Task Title: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';

    printf("Enter Priority (1-High, 2-Medium, 3-Low): ");
    scanf("%d", &priority);

    struct Task* newTask = createTask(id, title, priority);

    if (head == NULL) {
        head = newTask;
    } else {
        struct Task* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTask;
    }

    printf("Task added successfully!\n");
}

// Display all tasks
void displayTasks() {
    if (head == NULL) {
        printf("No tasks available.\n");
        return;
    }

    struct Task* temp = head;
    printf("\nTask List:\n");
    while (temp != NULL) {
        printf("ID: %d | Title: %s | Priority: %d | Status: %s\n",
               temp->id, temp->title, temp->priority,
               temp->completed ? "Completed" : "Pending");
        temp = temp->next;
    }
}

// Mark task as completed
void markCompleted() {
    int id;
    printf("Enter Task ID to mark as completed: ");
    scanf("%d", &id);

    struct Task* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            temp->completed = 1;
            printf("Task marked as completed!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Task not found.\n");
}

// Delete task
void deleteTask() {
    int id;
    printf("Enter Task ID to delete: ");
    scanf("%d", &id);

    struct Task *temp = head, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Task deleted successfully!\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Task not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Task deleted successfully!\n");
}

// Display pending tasks
void showPendingTasks() {
    struct Task* temp = head;
    int found = 0;

    printf("\nPending Tasks:\n");
    while (temp != NULL) {
        if (temp->completed == 0) {
            printf("ID: %d | Title: %s | Priority: %d\n",
                   temp->id, temp->title, temp->priority);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("No pending tasks!\n");
    }
}

// Main Menu
int main() {
    int choice;

    while (1) {
        printf("\n--- TASK MANAGER ---\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("5. View Pending Tasks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTask(); break;
            case 2: displayTasks(); break;
            case 3: markCompleted(); break;
            case 4: deleteTask(); break;
            case 5: showPendingTasks(); break;
            case 6: 
                printf("Exiting...\n");
                exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}