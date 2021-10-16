#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"
// Struct to hold the data and the pointer to the next element.
struct node
{
    int data;
    struct node *next;
};


node *top;

void initialize()
{
    top = NULL;
}
// Append the new element to the start of the stack
void push(int value)
{
    node *tmp;
    tmp = malloc(sizeof(node));
    tmp -> data = value;
    tmp -> next = top;
    top = tmp;
    
}
// Remove element from the top of the stack
int pop()
{
    node *tmp;
    int n;
    tmp = top;
    n = tmp->data;
    top = top->next;
    free(tmp);
    return n;
}
// Display the element at the top of the stack
int Top()
{
    return top->data;
}

void display(node *head)
{
    if(head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\n", head -> data);
        display(head->next);
    }
}
