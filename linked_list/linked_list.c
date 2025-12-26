

////////Class work 
// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node *link;
// };
// int main(){
//     struct node *head=malloc(sizeof(struct node));
//     head->data=45;
//     head->link= NULL;
//     return 0;
// }
   ///// TO genrate a linked list for  40,60,40,45
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
int main(){
    struct node *a=malloc(sizeof(struct node));
    a->data=45;
    
    a->link= NULL;
    printf("%d",a->data);
    
    
    struct node *b=malloc(sizeof(struct node));
    b->data=60;
    b->link= NULL;
    printf("%d",b->data);
    a->link=b;

struct node *c=malloc(sizeof(struct node));
    c->data=30;
    c->link= NULL;
    printf("%d",c->data);
    b->link=c;

//for circular c->link=a;
c->link=a;

    return 0;
}