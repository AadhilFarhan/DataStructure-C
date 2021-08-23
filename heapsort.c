#include <stdio.h>
void swap(int *x, int *y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void heap(int A[], int n, int i) 
{
    int root = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && A[left] > A[root])
        root = left;

    if (right < n && A[right] > A[root])
        root = right;

    if (root != i) 
    {
        swap(&A[i], &A[root]);
        heap(A, n, root);
    }
}
void heapsort(int A[], int n) 
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--) 
    {
        heap(A, n, i);
    }
    for (i = n - 1; i >= 0; i--) 
    {
        swap(&A[0], &A[i]);
        heap(A, i, 0);
    }
}
void main() 
{
    int A[100], i, n;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    printf("Enter array elements : ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &A[i]);
    }
    printf("Array before sorting is : ");
    for(i=0;i<n;i++)
    {
        printf("\t%d",A[i]);
    }
    heapsort(A, n);
    printf("\nArray after Heap Sort : ");
    for (i = 0; i < n; i++) 
    {
        printf("\t%d", A[i]);
    }

}