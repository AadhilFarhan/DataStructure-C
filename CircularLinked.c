#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *temp;
struct node *start;
int n,x;
void checkCircular()
{
    int i=1;
    while(i<=(n*2))
    {
    if(i==1)
    {
        printf("%d\t",start->data);
        temp=start->next;
        i++;
    }
    else
    {
        printf("%d\t",temp->data);
         temp=temp->next;
         i++;
    }
    } 
}
void changeEndnext()
{
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            temp=start->next;
        }
        else
        {
            temp=temp->next;
            if(i==n-1)
            {
                temp->next=start;
            }
        }
    }
}
void Display()
{
    printf("The entered data's are \n");
             for(int i=1;i<=n;i++)
            {
                if(i==1)
                {
                    printf("%d\t",start->data);
                    temp=start->next;
                }
                else
                {
                    printf("%d\t",temp->data);
                    temp=temp->next;
                    if(i==n)
                    {
                        break;
                    }
                }
            }
}
void main()
{
    int a,c,pos,i,item;
    x=0;
    printf("ENTER THE NUMBER OF NODES : ");
    scanf("%d",&n);
     struct node *newnode;
     struct node *temp1;
     for(int i=1;i<=n;i++)
     {
         newnode=malloc(sizeof(struct node));
         if(i==1)
         {
             printf("\n Enter the data to be stored");
             scanf("%d",&a);
             start=newnode;
             temp=newnode;
             newnode->data=a;
             newnode->next=NULL;

         }
         else
         {
             printf("\n Enter the data to be stored");
             scanf("%d",&a);
             temp->next=newnode;
             temp=newnode;
             newnode->data=a;
             if(i!=n)
             {
                 newnode->next=NULL;
             }
             else if(i==n)
             {
                 newnode->next=start;
             }
         }
     }
     Display();
     do{
     printf("\n\n1) Insert node at the beginning\n2) Enter node after a particular node\n3) Insert node at the end\n4) Delete a given Item\n5) DISPLAY \n6) EXIT\n7) CHECK \nENTER CHOICE : ");
     scanf("%d",&c);
     switch(c)
     {
         case 1 :
         {
             newnode=malloc(sizeof(struct node));
             temp=start;
             start=newnode;
             newnode->next=temp;
             printf("\n\nEnter the element to be inserted at the beginning");
             scanf("%d",&a);
             newnode->data=a;
             n=n+1;
             x++;
             changeEndnext();
             Display();
             break;
         }
         case 2 :
         {
             printf("\nEnter the new node position: ");
             scanf("%d",&pos);
             for(i=1;i<=n;i++)
             {
                 if(i==1)
                 {
                     temp=start->next;
                     if(i==pos-1)
                     {
                         newnode=malloc(sizeof(struct node));
                         newnode->next=temp;
                         start->next=newnode;
                         printf("\nEnter element to be entered : ");
                         scanf("%d",&a);
                         newnode->data=a;
                         n=n+1;
                     }
                 }
                 else
                 {
                     if(i<pos-1)
                     {
                         temp=temp->next;
                     }
                     else if(i==pos-1&&pos!=2)
                     {
                         newnode=malloc(sizeof(struct node));
                         temp1=temp->next;
                         temp->next=newnode;
                         newnode->next=temp1;
                         printf("\nEnter element to be entered : ");
                         scanf("%d",&a);
                         newnode->data=a;
                         n=n+1;
                     }
                     else if(i>pos-1)
                     {
                         break;
                     }
                 }
             }
             Display();
             break;
         }
         case 3 :
         {
             for(i=1;i<=n;i++)
             {
                 if(i==1)
                 {
                     temp=start->next;
                 }
                 if(i<n&&i!=1)
                 {
                     temp=temp->next;
                 }
                 if(i==n)
                 {
                     newnode=malloc(sizeof(struct node));
                     temp->next=newnode;
                     newnode->next=start;
                     n=n+1;
                     printf("\nEnter the data to  be inserted : ");
                     scanf("%d",&a);
                     newnode->data=a;
                     break;
                 }
             }
             Display(); 
             break;
         }
         case 4 :
         {
             printf("\nEnter the item to be deleted : ");
             scanf("%d",&item);
             for(i=1;i<=n;i++)
             {
                if(i==1)
                {
                    if(item==start->data)
                    {
                        start=start->next;
                        n--;
                        break;
                    }
                    else
                    {
                        temp=start->next;
                        temp1=start;
                    }   
                }
                else
                {
                    if(item==temp->data)
                    {
                        temp1->next=temp->next;
                        n--;
                        break;
                    }
                    else
                    {
                        temp1=temp;
                        temp=temp->next;
                    }
                    
                }
                
             }
             Display();
             changeEndnext();
             break;
         }
         case 5 : Display();
              break;
         case 6 : exit(0);
         case 7 : checkCircular();
     }}while(c!=5);
}