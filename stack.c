
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *top=NULL;

node *createnode(int x)
{
    node *newnode=(node*)malloc(sizeof(node));
    if(!newnode)
    {
        printf("memory not allocated.");
        exit(1);
    }
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}

void push(int x)
{
    node *newnode=createnode(x);
    if(top==NULL)
    {
        top=newnode;
    }
    newnode->next=top;
    top=newnode;
}

void pop()
{
    node *temp=top;
    if(top==NULL)
    {
        printf("stack is empty");
        return;
    }
    top=top->next;
    free(temp);


}

void display()
{
    if(top==NULL)
    {
        printf("stack is empty");
        return;
    }
    node *temp=top;
    printf("stack:\n");
    while(temp->next!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;

    }

}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
}
