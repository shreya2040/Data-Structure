#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct stack
{
    int a[N];
    int top;
}stack;
void init_stack(stack *);
void push(stack *);
void pop(stack *);
void peek(stack *);
int main()
{
    int c;
    stack s;
    init_stack(&s);
    while(1)
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Exit\nEnter a Choice : ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            push(&s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            peek(&s);
            break;
        case 4:
            exit(0);
        default :
            printf("\nEnter a Valid Choice\n");
        }
    }
    return 0;
}
void init_stack(stack *p)
{
    p->top=-1;
}
void push(stack *p)
{
    if(p->top==N-1)
    {
        printf("\nOverFlow\n");
    }
    else
    {
        printf("\nEnter Item to be Pushed : ");
        int e;
        scanf("%d",&e);
        p->top++;
        p->a[p->top]=e;
    }
}
void pop(stack *p)
{
    if(p->top==-1)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        printf("\nDeleted : %d\n",p->a[p->top]);
        p->top--;
    }
}
void peek(stack *p)
{
    if(p->top==-1)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        int i;
        printf("\nStack :\n");
        for(i=0;i<=p->top;i++)
        {
            printf("%d\t",p->a[i]);
        }
        printf("\n");
    }
}
