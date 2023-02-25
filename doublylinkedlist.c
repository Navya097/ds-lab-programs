#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
};
struct node *head=NULL;
void insertfront()
{
    int ele;
    struct node *p=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to be inserted\n");
    scanf("%d",&ele);
    p->data=ele;
    p->prev=NULL;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        printf("\nThe element inserted is %d",head->data);
        return;
    }
    p->next=head;
    head->prev=p;
    head=p;
    printf("\nThe element inserted is %d\n",head->data);
}
void insertend()
{
   int ele;
    struct node *p=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to be inserted\n");
    scanf("%d",&ele);
    p->data=ele;
    p->prev=NULL;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        printf("\nThe element inserted is %d",head->data);
        return;
    }
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
    p->prev=temp;
    printf("\nThe element inserted is %d",p->data);
}
void insertpos()
{
    int ele,pos;
    struct node *p=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to be inserted\n");
    scanf("%d",&ele);
    p->data=ele;
    p->prev=NULL;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        printf("\nThe element inserted is %d",p->data);
        return;
    }
    printf("\nEnter the position where the element is to be inserted\n");
    scanf("%d",&pos);
    if(pos==1)
    {
        p->next=head;
        head->prev=p;
        head=p;
        printf("\nElement inserted at position %d is %d\n",pos,p->data);
    }
    else
    {
        struct node *temp=head;
        int i=1;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        p->next=temp->next;
        temp->next->prev=p;
        temp->next=p;
        p->prev=temp;
        printf("\nElement inserted at position %d is %d\n",pos,p->data);
    }
}
void deletefront()
{
    struct node *p=head;
    if(head==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    if(head->next==NULL)
    {
        printf("\nElement deleted is %d\n",head->data);
        head=head->next;
        free(head);
        return;
    }
    head=head->next;
    head->prev=NULL;
    printf("\nElement deleted is %d\n",p->data);
    free(p);
}
void deleteend()
{
    struct node *temp=head,*ptr;
    if(head==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    while(temp->next!=NULL)
    {
        ptr=temp;
        temp=temp->next;
    }
    printf("\nElement deleted is %d\n",temp->data);
    ptr->next=NULL;
    free(temp);
}
void deletepos()
{
    int pos;
    struct node *p;
    if(head==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    printf("\nEnter the position where the element is to be deleted\n");
    scanf("%d",&pos);
    if(pos==1)
    {
        p=head;
        head=head->next;
        head->prev=NULL;
        printf("\nElement deleted at position %d is %d",pos,p->data);
        free(p);
        return;
    }
    struct node *temp=head;
    int i=1;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    p=temp->next;
    if(p->next==NULL)
    {
        temp->next=NULL;
        printf("\nElement deleted at position %d is %d",pos,p->data);
        free(p);
        return;
    }
    temp->next=p->next;
    p->next->prev=temp;
    printf("\nElement deleted at position %d is %d",pos,p->data);
    free(p);
}
void displayfront()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("\nList is empty\nNo elements to display\n");
        return;
    }
    printf("\nElements are:\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void displayend()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("\nList is empty\nNo elements to display\n");
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    printf("\nElements are:\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->prev;
    }
}
void main()
{
    int choice;
    printf("\n1.Insert at front\n2.Insert at end\n3.Insert at a position\n4.Delete at front\n5.Delete at end\n6.Delete at a position\n7.Display from front\n8.Display from end\n9.Exit");
    while(1)
    {   
        printf("\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insertfront();
                break;
            case 2:insertend();
                break;
            case 3:insertpos();
                break;
            case 4:deletefront();
                break;
            case 5:deleteend();
                break;
            case 6:deletepos();
                break;
            case 7:displayfront();
                break;
            case 8:displayend();
                break;
            case 9:exit(0);
        }
    }
}
