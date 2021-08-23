#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

void insertion(int newdata)
{
	struct node *current;
	struct node *parent;
	struct node *tempnode=(struct node *)malloc(sizeof(struct node));
	tempnode->data=newdata;
	tempnode->left=NULL;
	tempnode->right=NULL;
	if(root==NULL)
		root=tempnode;
	else
	{
		current=root;
	    parent=NULL;
	while(1)
	{
		parent=current;
		if(tempnode->data < parent->data)
		{
			current=current->left;
			if(current==NULL)
			{
				parent->left=tempnode;
				return;
			}
		}
		else
		{
			current=current->right;
			if(current==NULL)
			{
				parent->right=tempnode;
				return;
			}
		}
	}
	}
}

void preorder(struct node *root)
{
	if(root==NULL)
		return;
	printf("%d \t",root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d \t",root->data);
	inorder(root->right);
}

void postorder(struct node *root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d \t",root->data);
}

void main()
{
	int n,i,newdata,o,flag;
	printf("Enter the number of nodes in the binary tree : ");
	scanf("%d",&n);
	root=NULL;
	printf("Enter %d elements : ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&newdata);
		insertion(newdata);
	}
	flag=0;
	while(flag==0)
	{
	    printf("\nEnter the operation");
	    printf("\n1. Preorder traversal\n2. Inorder traversal\n3. Postorder traversal\n4. Exit\n");
	    scanf("%d",&o);
	    switch(o)
	    {
		    case 1:preorder(root);
		           break;
		    case 2:inorder(root);
		           break;
		    case 3:postorder(root);
    		       break;
		    case 4:flag=1;
                   break;		
	    }
	}
}