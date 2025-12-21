#include<stdio.h>
#define N 5
int stack[5];
int top=-1;
 

void push(int x)
{
    if(top==-1)
    {
        printf("The  stack is overload .");
    }
    else{
        top++;//adds after -1 (doesnot counts -1)
        stack[top]=x;
        printf("pushed:%d",&x);
    }

}

void pop()
{
    int item;
    if(top==-1)
    {
        
    }
}