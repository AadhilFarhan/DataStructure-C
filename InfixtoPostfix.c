#include<stdio.h>
#include<string.h>
#define MAX 20
int posttop,Optop;
int isOperator(char a)
{
    if(a=='*' || a=='-' || a=='+' || a=='/' || a=='(' || a==')'|| a=='^')
    {
        return 1;
    }
    else
    {
        return 0;
    } 
    
}

int precedence(char chara)
{
    switch(chara)
    {
	    case '^':return 3;
	    case '/':
	    case '*':return 2;
	    case '+':
	    case '-':return 1;
	    default:return -1;
    }
}

void main()
{
    char S[MAX],OpStack[MAX],postfix[MAX];
    char Symb,topSymb;
    posttop=Optop=-1;
    printf("Enter the infix expresion: ");
    scanf("%s",S);
    for(int i=0;i<strlen(S);i++)
    {
        Symb=S[i];
        if(!isOperator(S[i]))
        {
	        ++posttop;
	        postfix[posttop]=Symb; 
        }
        else if(Symb=='(')
        {
            ++Optop;
            OpStack[Optop]=Symb;
        }
        else if(Symb==')')
        {
            while(OpStack[Optop]!='(')
            {
                topSymb=OpStack[Optop];
	            Optop--;  
                ++posttop;
	            postfix[posttop]=topSymb;  
            }
        }
        else
        {
            while(Optop>-1 && precedence(Symb)<=precedence(OpStack[Optop]))
            {
	            topSymb=OpStack[Optop];
	            Optop--;   
	            ++posttop;
	            postfix[posttop]=topSymb; 
            }
            if(Optop==-1 || Symb!=')')
            {
                ++Optop;
	            OpStack[Optop]=Symb;    
            }
            else
            {
	   	        topSymb=OpStack[Optop];
	            Optop--;   
            }
        }
    }
    while(Optop>-1)
    {
	 	topSymb=OpStack[Optop];
	    Optop--;   
   	    ++posttop;
	    postfix[posttop]=topSymb; 
    }
    printf("Prefix form of the expression is \n");
    for(int j=0;j<=posttop;j++)
    {
        if(postfix[j]!='(')
        {
            printf("%c",postfix[j]);
        }
    }
}
