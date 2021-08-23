#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *temp, *start;

void Display(int n)
{
    temp = start;
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void main()
{
    int n, c, choice, data, pos;
    printf("Enter initial number of nodes : ");
    scanf("%d", &n);
    printf("\n Enter datas");
    struct node *newnode;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            newnode = malloc(sizeof(struct node));
            scanf("%d", &c);
            newnode->data = c;
            newnode->prev = NULL;
            newnode->next = NULL;
            start = newnode;
            temp = newnode;
        }
        else
        {
            newnode = malloc(sizeof(struct node));
            scanf("%d", &c);
            newnode->data = c;
            newnode->next = NULL;
            newnode->prev = temp;
            temp->next = newnode;
            temp = newnode;
        }
    }
    Display(n);
    printf("Enter the choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        printf("\nEnter the data to be deleted: ");
        scanf("%d", &data);
        temp = start;
        for (int i = 1; i <= n; i++)
        {
            if (temp->next == NULL && data == temp->data)
            {
                (temp->prev)->next = NULL;
                temp->prev = NULL;
                --n;
            }
            else if (data == temp->data)
            {
                (temp->prev)->next = temp->next;
                (temp->next)->prev = temp->prev;
                --n;
            }
            else
            {
                temp = temp->next;
            }
        }
        Display(n);
        break;
    }
    case 2:
    {
        printf("\n Enter the position : ");
        scanf("%d", &pos);
        temp = start;
        for (int i = 1; i <= n; i++)
        {
            if (i == pos)
            {
                newnode = malloc(sizeof(struct node));
                printf("Enter the data :");
                scanf("%d", &data);
                newnode->data = data;
                newnode->prev = temp->prev;
                newnode->next = temp;
                (temp->prev)->next = newnode;
                temp->prev = newnode;
                ++n;
                Display(n);
            }
            else
            {
                temp = temp->next;
            }
        }
        break;
    }
    }
}