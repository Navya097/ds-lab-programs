#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node{
    int val;
    struct node *next;
};
struct node *head;
void push()
{
    int val;
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("not able to push element");
    }
    else
    {
       printf("enter value");
       scanf("%d",&val);
       if(head==NULL)
       {
        ptr->val=val;
        ptr->next=NULL;
        head=ptr;
       }
       else{
         ptr->val=val;
        ptr->next=head;
        head=ptr;
       }
       printf("item pushed");
    }
}
void pop()
{
    int item;
    struct node *ptr;
    if(head==NULL)
    {
        printf("underflow");
    }
    else
    {
        item=head->val;
        ptr=head;
        head=head->next;
        free(ptr);
        printf("item popped");
    }
}
void display()
{
    int i;
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("stack is empty");
    }
    else
    {
     printf("printing stack ele");
     while(ptr!=NULL)
     {
        printf("%d\n",ptr->val);
        ptr=ptr->next;
     }
    }
}
int main()
{
    int choice;
    while(1)
    {
     printf("op performed by stack");
     printf("\n1.push\n 2.pop\n 3.display\n 4.exit\n");
     printf("enter the choice");
     scanf("%d",&choice);
    switch(choice)
    {
        case 1:push();
               break;
        case 2:pop();
        break;
        case 3:display();
        break;
        case 4:exit(0);
        default:printf("invalid choice");
    }
    }
}