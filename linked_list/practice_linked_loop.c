#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

int main() {
    // Create head node
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;
    
    // ptr points to head initially
    struct node *ptr = head;
    
    // Loop from 2 to 100
    for(int i = 2; i <= 100; i++) {
        // Create new node (current)
        struct node *current = (struct node*)malloc(sizeof(struct node));
        current->data = i;
        current->link = NULL;
        
        // This is where the magic happens
        // ptr.link = current (link previous node to current node)
        ptr->link = current;
        
        // Move ptr to current for next iteration
        ptr = current;
    }
    
    // Display the linked list
    printf("Linked list from 1 to 100:\n");
    ptr = head;
    int count = 0;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
        count++;
        if(count % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n\nTotal nodes: %d\n", count);
    
    // Free memory
    ptr = head;
    while(ptr != NULL) {
        struct node *temp = ptr;
        ptr = ptr->link;
        free(temp);
    }
    
    return 0;
}