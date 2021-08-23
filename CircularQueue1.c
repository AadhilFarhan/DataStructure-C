#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int CircQue[SIZE];
int front,rear;
int isEmpty()
{
    if(front==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int isFull()
{
    if(front==0&&rear==SIZE-1||front==rear+1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void CQinsert(int item)
{
    if(!isFull())
    {
        if(front==-1&&rear==-1)
        {
            front=rear=0;
            CircQue[rear]=item;
        }
        else
        {
            rear=(rear+1)%SIZE;
            CircQue[rear]=item;
        }
    }
    else if(isFull())
    {
        printf("QUEUE IS FULL");
    }
}
void CQdelete()
{
    int data;
    if(isEmpty())
    {
        printf("The queue is Empty");
    }
    else
    {
        data=CircQue[front];
        if(front==rear)
        {
            front=rear=-1;
            printf("Removed item is %d\n", data);
        }
        else
        {
            front=(front+1)%SIZE;
            printf("Removed item is %d\n", data);
        }
    }
    
}
void main()
{
     int s,item;
    while(s!=3)
    {
        printf("\n\n1) ENTER ELEMENT\n2) DELETE ELEMENT\n3) EXIT\nEnter the choice: ");
        scanf("%d",&s);
        if(s==1||s==2||s==3)
        {
            switch(s)
            {
                case 1 : {
                    printf("Enter element");
                    scanf("%d",&item);
                    CQinsert(item);
                    break;
                }
                case 2 : CQdelete();
                         break;
                case 3 : exit(0);
            }
        }
        else
        {
            printf("Invalid choice");
        }
    }
}