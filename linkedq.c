#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

// Global pointers initialized to NULL
struct node *newnode, *f = NULL, *r = NULL, *temp;

// Enqueue operation
void en(int item) 
{
    newnode = (struct node *) malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Overflow!\n");
        return;
    }
    
    newnode->data = item;
    newnode->next = NULL;

    if (f == NULL && r == NULL) {
        f = r = newnode;
    } else {
        r->next = newnode;
        r = newnode;
    }
    printf("Inserted: %d\n", item);
}

// Dequeue operation
void de() 
{
    if (f == NULL) {
        printf("Underflow! Queue is empty.\n");
    } else {
        temp = f;
        printf("Deleted element: %d\n", temp->data);
        f = f->next;
        
        // If queue becomes empty, reset rear to NULL as well
        if (f == NULL) {
            r = NULL;
        }
        free(temp);
    }
}

// Display operation
void display() 
{
    if (f == NULL) {
        printf("Queue is empty.\n");
    } else {
        temp = f;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() 
{
    int choice, value, ch;

    do {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                en(value);
                break;

            case 2:
                de();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }

        printf("Do you want to continue? (1 for Yes / 0 for No): ");
        scanf("%d", &ch);

    } while (ch == 1);

    return 0;
}