#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int info;
    struct stack*next;
}stack;
void push(stack **);
void pop(stack **);
void display(stack **);
int main()
{
    stack *top=NULL;
    int c;
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter a Choice : ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            push(&top);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            display(&top);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEnter valid Choice\n");
        }
    }
    return 0;
}
void push(stack **t)
{
    int element;
    stack *newnode;
    newnode = (stack *)malloc(sizeof(stack));
    printf("Enter Element to be Pushed\n");
    scanf("%d",&element);
    newnode->info=element;
    newnode->next=NULL;
    if(*t==NULL)
    {
        *t=newnode;
    }
    else
    {
        newnode->next=*t;
        *t=newnode;
    }
}
void pop(stack **t)
{
    if(*t==NULL)
    {
        printf("\nStack Empty\n");
    }
    else
    {
        stack *temp;
        temp=*t;
        *t=(*t)->next;
        printf("\nDeleted %d\n",temp->info);
        free(temp);
    }
}
void display(stack **t)
{
    stack *temp;
    printf("\nStack Contains :\n");
    for(temp=*t;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->info);
    }
}
