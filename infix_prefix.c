#include<stdio.h>
#include<string.h>
#include<ctype.h>              //used for (isalnum())
#define max 100
int top=-1, a[max];         //global declaration
void push(char x)           //push function here, inserts value in stack and increments by one
{
    a[++top]=x;
}
char pop()                 //function to remove an element and decreases by one 
{ 
if(top==-1)
return -1;
else
return a[top--];
}

int prcd(char c)                 //precedence according to operator 
{  
 if(c==')')
    return 0;
    else if(c=='+'||c=='-')
    return 1;
    else if(c=='*'||c=='/')
    return 2;
}
void infixtoprefix(char infix[max],char prefix[max])         //converts infix to postfix expression
{
    char temp,x;
    int i=0,j=0;
    strrev(infix);    //reverse the expression 
    while(infix[i]!='\0')
    {
        temp=infix[i];
       if(isalnum(temp))
        {
            prefix[j++]=temp;
        }
        else if(temp==')')
         push(temp);
        else if(temp=='(')
            {
         while((x=pop())!=')')
         {
          prefix[j++]=x;
           }
          }
        else
        {  
         while(prcd(a[top])>=prcd(temp))
         {
            prefix[j++]=pop();}
            push(temp);
        }
        i++;
    }
    while(top!= -1)
    prefix[j++]=pop();
    prefix[j]='\0';
    strrev(prefix);               //reverse the expression
}
int main()       //main function
{
    char infix[max],prefix[max];
    printf("Enter the infix expression\n");
    gets(infix);
    printf("The infix expression is %s\n",infix);
    infixtoprefix(infix, prefix);                             //function calling 
    printf("The prefix expression is %s\n",prefix);
}
