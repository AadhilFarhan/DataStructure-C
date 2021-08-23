#include<stdio.h>
void main()
{
    char c;
    printf("Enter character");
    scanf("%c",&c);
    if((c>=65&&c<=90)||(c>=97&&c<=122))
    {
        printf("PODA");
    }
    else
    {
        printf("podi");
    }
    
}