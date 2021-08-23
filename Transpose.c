#include<stdio.h>
typedef int mat [20][20];
typedef struct obj{
    int row;
    int col;
    int valueue;
}data;
void SparseDisplay(mat S,int l,int e)
{
    for(int i=0;i<l;i++)
    {
        printf("\n");
        for(int j=0;j<e;j++)
        {
            printf("%d \t",S[i][j]);
        }
    }
}
void ConvAndPrint(mat S, data A[], int m,int n)
{
    int f=1,w,x,y;
    for(w=0;w<m;w++)
    {
        for(x=0;x<n;x++)
        {
            if(S[w][x]!= 0)
            {
                A[f].valueue=S[w][x];
                A[f].row=w;
                A[f].col=x;
                f++;
            }
        
        }
    }
   
    A[0].row=m;
    A[0].col=n;
    A[0].valueue=f-1;
    for(y=0;y<f;y++)
    {
        printf("%d\t",A[y].row);
        printf("%d\t",A[y].col);
        printf("%d\n",A[y].valueue);
    }

}
void transpose(data A[])
{
    int temp;
    for(int i=0;i<=A[0].valueue;i++)
    {
        temp=A[i].row;
        A[i].row=A[i].col;
        A[i].col=temp;
    }

}
void TupplePrint(data A[])
{
    int y;
    for(y=0;y<=A[0].valueue;y++)
    {
        printf("%d\t",A[y].row);
        printf("%d\t",A[y].col);
        printf("%d\n",A[y].valueue);
    } 
}
void TupleToMatrix(mat S,data A[])
{
    int i,j;
    for(i=0;i<A[0].row;i++)
    {
        for(j=0;j<A[0].col;j++)
        {
            S[i][j]=0;
        }
        
    }
    for(i=1;i<=A[0].valueue;i++)
    {
        S[A[i].row][A[i].col]=A[i].valueue;
    }
    for(i=0;i<A[0].row;i++)
    {
        printf("\n");
        for(j=0;j<A[0].col;j++)
        {
            printf("%d\t",S[i][j]);

        }
    }


}
int main()
{
    int i;
    int a,b;
    mat S1,S2;//S2 is a zero matrix in which the transpose matrix will be stored
    data A1[20];
    printf("Enter the number of rows and columns of the matrix:");
    scanf("%d%d",&a,&b);
    printf("\nEnter the elements of the matrix ");
    for(i=0;i<a;i++)
    {
        for( int j=0;j<b;j++)
        {
            scanf("%d",&S1[i][j]);
        }
    }
    printf("\nThe sparse matrix is:\n");
    SparseDisplay(S1,a,b);
    printf("\nThe tupple form of the sparse matrix is:\n");
    ConvAndPrint(S1,A1,a,b);
    transpose(A1);
    printf("\nThe transpose tuple is:\n");
    TupplePrint(A1);
    printf("\nThe transpose matrix is:\n");
    TupleToMatrix(S2,A1);
    return 0;
}