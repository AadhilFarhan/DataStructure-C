#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};
int count=0;
struct node *root=NULL;
void leafnodecount(struct node *root)
{
    
    struct node *current=root;
    if(root==NULL)
    {
        return;
    }
    else{
    leafnodecount(current->left);
    if(current->left==NULL && current->right==NULL)
    {
        count++;
    }
    
    leafnodecount(current->right);
}}

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

void inorder(struct node *root)
{
    if(root==NULL)
        return;
    printf("%d\t",root->data);
    inorder(root->left);
    inorder(root->right);
}
struct node *parent=NULL;
void delete(struct node *root, int key)
{
    if(root==NULL)
    {
        return;
    }
    if(key<root->data)
    {
        parent=root;
        delete(root->left,key);
    }
    else if(key>root->data)
    {
        parent=root;
        delete(root->right,key);
    }
    else{
        if(root->left==NULL&&root->right==NULL)
        {
            free(root);
        }
        else if(root->left!=NULL&&root->right==NULL)
        {
            parent->left=root->left;
            free(root);
        }
        else if(root->left==NULL&&root->right!=NULL)
        {
            parent->right=root->right;
            free(root);
        }
        else if(root->left!=NULL&&root->right!=NULL)
        {
            if(root->data<parent->data)
            {
                parent->left=root->left;
                
                free(root;)
            }
        }
    }

}

void main()
{
    int n,newdata;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&newdata);
        insert(newdata);
    }
    inorder(root);
    leafnodecount(root);
    printf("\nnumber of leafnodes = %d", count);
}