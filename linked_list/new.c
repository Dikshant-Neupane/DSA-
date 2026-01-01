                            /////My version

// #include<stdio.h>

    // #include<stdlib.h>
    // struct node{
    //     int data;
    //     struct node *link
    // };
    // int main()
    // {
    //     int n;
    //     struct node *head=NULL, *temp=NULL,*newnode=NULL;
    //     printf("Enter the n upto which you want to create a node ");
    //     scanf("%d",&n);
    //     for (int i=1;i<=n;i++){
    //         newnode =(struct node *)malloc(sizeof(struct node));
    //         newnode->data=i;
    //         newnode->link=NULL;

        
    //     if(head==NULL){
    //         head=newnode;
    //         temp=head;

    //     }
    //     else{
    //         temp->link=newnode;
    //         temp=newnode;
    //     }}
    //     temp=head;
    //     while(temp !=NULL){
    //         printf("%d->",temp->data);
    //         temp=temp->link;
    //     }
    //     printf("NUll");
    //     return 0;


    // }




        ////////////////SIr's Version



#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list of size n
void create_linklist(struct Node** head, int n) {
    struct Node *newNode, *temp;
    int data, i;

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

    return 0;
}