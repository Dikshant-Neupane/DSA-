#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list of size n
void create_linklist(struct Node** head, int n) {
    struct Node *newNode, *temp;//duita pointer use garne  bhayera node**
    int  i;

    if (n <= 0) {
        *head = NULL;
        return;
    }

    for (i = 1; i <= n; i++) {
        // Allocate memory for a new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        
        // printf("Enter data for node %d: ", i);
        // scanf("%d", &data);
        
        newNode->data = i;
        newNode->next = NULL;

        // If it's the first node, set it as head
        if (*head == NULL) {
            *head = newNode;
            temp = *head;
        } else {
            // Link the new node to the end of the list
            temp->next = newNode;
            temp = temp->next;
        }
    }

}

// Function to insert a node at the front
void insert_front(struct Node** head, int data) {
    // Allocate memory for new node
    struct Node* frontNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign data to the new node
    frontNode->data = data;
    
    // Make new node point to the current head
    frontNode->next = *head;
    
    // Update head to point to the new node
    *head = frontNode;
}

// Helper function to print the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter the number of nodes (n): ");
    scanf("%d", &n);

    // Call the function with address of head and n
    create_linklist(&head, n);

    displayList(head);

    // Insert a node at the front
    printf("\nInserting 100 at the front...\n");
    insert_front(&head, 100);
    displayList(head);

    return 0;
}