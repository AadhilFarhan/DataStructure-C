#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    int data;
    struct node *right;
};
struct node *root;
void printleaf(struct node *root)
{
    if(root->left==NULL&&root->right==NULL)
    {
        printf("\t%d",root->data);
    }
    else{

    printleaf(root->left);
    printleaf(root->right);
    }
    
}
void insert(int newdata)
{
    struct node *current;
    struct node *parent;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
    {
        root=newnode;
    }
    else
    {
        current=root;
        parent=NULL;
        while(1){
        if(newnode->data<current->data)
        {
            parent=current;
            current=current->left;
            if(current==NULL)
            {
                parent->left=newnode;
                current=newnode;
                return;
            }
        }
        else if(newnode->data>=current->data)
        {
            parent=current;
            current=current->right;
            if(current==NULL)
            {
                parent->right=newnode;
                current=newnode;
                return;
            }

        }}
    }
}
void main()
{
    int a,n;
    root=NULL;
    printf("Enter number of nodes");
    scanf("%d",&a);
    printf("\nEnter the elements : ");
    for(int i=1;i<=a;i++)
    {
        scanf("%d",&n);
        insert(n);
    }
    printleaf(root);


}