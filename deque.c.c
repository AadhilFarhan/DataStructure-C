#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int front1=-1,rear1=-1,item,front2=-2,rear2=-2;
int queue[MAXSIZE];
void enqueuefront()
{
    if(rear1!=rear2||rear1!=MAXSIZE)
    {
    
        if(front1==-1&&rear1==-1)
        {
            front1=0;
            rear1=0;
            printf("\nEnter the element to be pushed into the queue from the front :");
            scanf("%d",&item);
            queue[rear1]=item;
        }
        else
        {
            ++rear1;
            printf("\nEnter the element to be pushed into the queue from the front :");
            scanf("%d",&item);
            queue[rear1]=item;
        }
   }

    else
    {
        printf("\nThe queue is full");
        
    }

}
void enqueuerear()
{
    if(rear2!=rear1||rear2!=0)
    {
    
        if(front2==-2&&rear2==-2)
        {
            front2=MAXSIZE;
            rear2=MAXSIZE;
            printf("\nEnter the first element to be pushed into the queue from rear side :");
            scanf("%d",&item);
            queue[rear2]=item;
        }
        else
        {
            --rear2;
            printf("\nEnter the element to be pushed into the queue from the rear side :");
            scanf("%d",&item);
            queue[rear2]=item;
        }
   }

    else
    {
        printf("\nThe queue is full");
        
    }

}
void deletefront()
{
    int data;
    if(front1!=-1)
    {
        if(rear1>=front1)
        {
            data=queue[front1];
            front1++;
            printf("\nThe element deleted from the front side of the queue is %d",data);
        }
        if(front1>rear1)
        {
            front1=-1;
        }
    }
    else if(front1==-1&&front2==-2)
    {
        printf("\nThe queue is empty");
    }
    else if(front1==-1||front1>rear1)
    {
        printf("\nThe queue from the front is empty");
    }
}
void deleterear()
{
    int data;
    if(front2!=-2)
    {
        if(rear2<=front2)
        {
            data=queue[front2];
            front2--;
            printf("\nThe element deleted from the rear side of the queue is %d",data);
        }
        if(rear2>front2)
        {
            front2=-2;
        }
    }
    else if(front1==-1&&front2==-2)
    {
        printf("\nThe queue is empty");
    }
    else if(front2==-2||front2<rear2)
    {
        printf("\nThe queue from the rear is empty");
    }
}
void main()
{
    int s;
    do{
        printf("\n\n1) ENTER ELEMENT(FRONT)\n2) ENTER ELEMENT(REAR)\n3) DELETE ELEMENT(FRONT)\n4) DELETE ELEMENT(REAR)\n5) EXIT\nEnter the choice: ");
        scanf("%d",&s);
        if(s==1||s==2||s==3||s==4||s==5)
        {
            switch(s)
            {
                case 1 : enqueuefront();
                         break;
                case 2 : enqueuerear();
                         break;
                case 3 : deletefront();
                         break;
                case 4 : deleterear();
                         break;
                case 5 : exit(0);
            }
        }
        else
        {
            printf("Invalid choice");
        }
    }while(s!=5);
}