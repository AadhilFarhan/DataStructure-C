#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

void insertnode(int newdata)
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

struct node *search(int searchdata)
{
	struct node *current=root;
	while(current->data != searchdata)
	{
		if(current!=NULL)
		{
			if(current->data > searchdata)
				current=current->left;
			else
				current=current->right;
		}
		if(current==NULL)
			return NULL;
	}
	return current;
}
int searchsiblings(struct node *root,int nodedata)
{
	struct node *found=search(nodedata);
	if(found==NULL)
	{
		printf("Element not found");
		return 0;
	}
	struct node *current1;
	struct node *current2;
	current1=root->left;
	current2=root->right;
	if(root->data==nodedata)
	{
		printf("Root node data\nHave no siblings");
		return 0;
	}
	else if(current1->data==nodedata)
	{
		printf("Sibling node's data is %d",current2->data);
		return 0;
	}
	else if(current2->data==nodedata)
	{
		printf("Sibling node's data is %d",current1->data);
		return 0;
	}
	else if(current1->data==nodedata&&current2==NULL)
	{
		printf("No siblings");
		return 0;
	}
	else if(current2->data==nodedata&&current1==NULL)
	{
		printf("No siblings");
		return 0;
	}
	else if(nodedata<root->data)
	{
		searchsiblings(current1,nodedata);
	}
	else if(nodedata>=root->data)
	{
		searchsiblings(current2,nodedata);
	}
}

struct node *deletenode(struct node *root,int key) 
{
	struct node *found=search(key);
	if(found==NULL)
	{
		printf("Element not found");
		return 0;
	}
	else
    {
        if (root == NULL) 
            return root;
        if (key < root->data)
            root->left = deletenode(root->left, key);
        else if (key > root->data)
            root->right = deletenode(root->right, key);
        else 
        {
            if (root->left == NULL) 
            {
                struct node *temp = root->right;
                free(root);
                return temp;
            } 
            else if (root->right == NULL) 
            {
                struct node *temp = root->left;
                free(root);
                return temp;
            }
            struct node *current = root;
            while (current && current->left != NULL)
                current = current->left;
            struct node *temp=current;
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
        }
        return root;
	}
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d \t",root->data);
	inorder(root->right);
}

void main()
{
	int n,i,insertelement,o,flag,x,item,nodedat;
	printf("Enter the number of nodes in the binary tree : ");
	scanf("%d",&n);
	root=NULL;
	printf("\nEnter the elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&insertelement);
		insertnode(insertelement);
	}
	flag=0;
	while(flag==0)
	{
	printf("\nEnter the operation to be performed");
	printf("\n1.Insert element\n2.Delete element\n3.Search element\n4.Traverse(inorder)\n5.Exit\n");
	scanf("%d",&o);
	switch(o)
	{
		case 1:printf("Enter the element to be inserted\t");
		       scanf("%d",&insertelement);
		       insertnode(insertelement);
		       break;
		case 2 : 
               printf("Enter the element to be deleted\t");
		       scanf("%d",&x);
		       root=deletenode(root,x);
		       break;
		case 3:
               printf("Enter the element to be searched\t");
		       scanf("%d",&item);
		       struct node *found=search(item);
			   if(found==NULL)
			   {
                   printf("Not found");
               }
			   else
				{
                   printf("%d is present in the tree",item);
                }
    		   break;
        case 4:inorder(root);
               break;
		case 5:flag++;
               break;	
		case 6:printf("Enter the node data to be searched");
		       scanf("%d",&nodedat);
		       searchsiblings(root,nodedat);
		       break;
        default:printf("Invalid entry\n");
               break;
	}
	}
}