#include<stdio.h>
#define size 5

int arr[size],rear=-1,front=-1;
void enqueue(int d)
{
    if(rear==size-1)
    {
        printf("queue is full\n");
        return;
    }
    if(rear==-1)
    {
        ++front;
    }
    ++rear;
    arr[rear]=d;
}
int dequeue()
{
    if(front==-1 || front>rear)
    {
         printf("queue is empty");
         return -1;
    }

    int d=arr[front];
    ++front;

}
void display()
{
   if(front==-1|| front>rear)
   {
       printf("queue is empty\n");
       return;
   }
   for(int i=front;i<=rear;i++)
   {
       printf("%d\t",arr[i]);
   }
   printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    dequeue();
    display();


}
