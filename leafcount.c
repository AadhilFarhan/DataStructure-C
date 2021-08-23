/* C Program to find the number of leaf nodes in a Tree */
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node* left, *right;
 
};
 
struct node *root;
 


void insert(int newdata)
{
    struct node *current, *parent;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->left=newnode->right=NULL;
    if(root==NULL)
    {
        root=newnode;
    }
    else{
        current=root;
        parent=NULL;
        while(1)
        {
            parent=current;
            if(newnode->data<root->data)
            {
                current=current->left;
                if(current==NULL)
                {
                    parent->left=newnode;
                    return;
                }
            }
            else{
                current=current->right;
                if(current==NULL){
                    parent->right=newnode;
                    return;
                }
            }
        }
    }
}
 
/* 
 * Function to count number of leaf nodes
 */
 
int count = 0;
int leafnodes(struct node* newnode)
{
 
    if(newnode != NULL)
    {
        leafnodes(newnode->left);
        if((newnode->left == NULL) && (newnode->right == NULL))
        {
            count++;
        }
        leafnodes(newnode->right);
    }
    return count;
 
}
 
/*
 * Main Function
 */
 
int main()
{
    int n,newdata;
   printf("Number of nodes : ");
   scanf("%d", &n);
   printf("\nEnter elements");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&newdata);
        insert(newdata);
    }

    printf("Number of leafnodes : %d", leafnodes(root));

 
    return 0;
}