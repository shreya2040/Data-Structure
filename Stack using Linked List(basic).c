#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int info;
    struct stack*next;
}stack;
stack *top=NULL,*temp;
void push();
void pop();
void display();
int main()
{
    int c;
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter a Choice : ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter valid Choice");
        }
    }
    return 0;
}
void push()
{
    int element;
    stack *newnode;
    newnode = (stack *)malloc(sizeof(stack));
    printf("Enter Element to be Pushed\n");
    scanf("%d",&element);
    newnode->info=element;
    newnode->next=NULL;
    if(top==NULL)
    {
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
}
void pop()
{
    if(top==NULL)
    {
        printf("\nStack Empty\n");
    }
    else
    {
        temp=top;
        top=top->next;
        printf("\nDeleted %d\n",temp->info);
        free(temp);
    }
}
void display()
{
    printf("\nStack Contains :\n");
    for(temp=top;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->info);
    }
}
