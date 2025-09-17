
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head=NULL;

node* createnode(int x)
{
    node *newnode=(node*)malloc(sizeof(node));
    if(!newnode)
    {
        printf("memory not allocated");
        exit(1);
    }
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}


void insert_begin(int x)
{
    node *newnode=createnode(x);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        node* temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        newnode->next=head;
        temp->next=newnode;
        head=newnode;

    }
}




void insert_end(int x)
{
    node *newnode=createnode(x);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
}




void deletenode(int x)
{
    if(head==NULL)
    {
        printf("list is empty");
        return;
    }
    node *temp=head;
    node *prev=NULL;

    if(head->data==x)//to delete head
    {
        if(head->next==head)
        {
            free(head);
            head=NULL;
            return;
        }

        node *last=head;
        while(last->next!=head)
        {
            last=last->next;
        }
        last->next=head->next;
        temp=head;
        head=head->next;
        free(temp);
        return;

    }

    //for non head nodes

    do
    {
        prev=temp;
        temp=temp->next;
        if(temp->data==x)
        {
            prev->next=temp->next;
            free(temp);
            return;
        }

    }while(temp!=head);
    /*here why we are using dowhile is that if we use while
        temp = head;
while (temp != head) {   // FALSE immediately on first check
    ...
}because it is a circular linked list initially (temp==head)
so head will never be checked.
*/

    printf("element not found");
}


void search(int x)
{
    if(head==NULL)
    {
        printf("the list is empty");
        return;
    }

    node *temp=head;
    int position=1;
    do
    {
        if(temp->data==x)
        {
            printf("the element found at position %d",position);
            return;
        }
        temp=temp->next;
        position++;
    }while(temp!=head);
    printf("the element not found");
}


void display()
{
    if(head==NULL)
    {
        printf("the list is empty");
        return;
    }
     node *temp=head;
     printf("list:\n");
     do
     {
         printf("%d",temp->data);
         temp=temp->next;

     }while(temp!=head);
     printf("\n");
}




int main() {
    int x,choice, value;

    while (1) {
        printf("\n--- Singly Circular Linked List ---\n");
        printf("1. Insert at Begin\n");
        printf("2. Insert at End\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Delete\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("enter the number of element to insert:");
            scanf("%d",&x);
            for(int i=1;i<=x;i++)
            {
                printf("enter the element:");
                scanf("%d",&value);
                insert_begin(value);
            }
            display();
            printf("\n");
            break;
        case 2:
            printf("enter the number of element to insert:");
            scanf("%d",&x);
            for(int i=1;i<=x;i++)
            {
                printf("enter the element:");
                scanf("%d",&value);
                insert_end(value);
            }
            display();
            printf("\n");
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 5:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deletenode(value);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}






