
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node* head=NULL;

node* create_list(int x)
{
    node* newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("memory is not allocated");

    }
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}

void insert_front(int x)
{
    node* temp=create_list(x);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    temp->next=head;
    head=temp;
}

void display()
{
    if(head==NULL)
    {
        printf("list is empty");
        return;
    }
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}

void element_search(int x)
{
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        node *temp=head;
        while(temp!=NULL)
        {

            if(x==temp->data)
            {
                printf("element is found in the list");
                return;
            }
            temp=temp->next;
        }
        printf("element not found");
    }
}

int main()
{
    int n,x;
    printf("enter the number of element to insert:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("enter the element:");
        scanf("%d",&x);
        insert_front(x);
        display();
        printf("\n");
    }
    int search;
    printf("enter the element to search:");
    scanf("%d",&search);
    element_search(search);


}
