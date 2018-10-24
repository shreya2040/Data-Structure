#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct queue
{
    int a[N];
    int front;
    int rear;
}queue;
void init_queue(queue * );
void enqueue(queue * );
void dequeue(queue * );
void peek(queue * );
int main()
{
    int c;
    queue q;
    init_queue(&q);
    while(1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\nEnter a Choice : ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            peek(&q);
            break;
        case 4:
            exit(0);
        default :
            printf("\nEnter a Valid Choice\n");
        }
    }
    return 0;
}
void init_queue(queue *p)
{
    p->front=-1;
    p->rear=-1;
}
void enqueue(queue *p)
{
    if(p->rear==N-1)
    {
        printf("\nOverFlow\n");
    }
    else
    {
        printf("\nEnter Item to be Enqueued : ");
        int e;
        scanf("%d",&e);
        if(p->front==-1&&p->rear==-1)
        {
            p->front++;
            p->rear++;
            p->a[p->rear]=e;
        }
        else
        {
            p->rear++;
            p->a[p->rear]=e;
        }
    }
}
void dequeue(queue *p)
{
    if(p->rear==-1)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        int i;
        printf("\nDeleted : %d\n",p->a[p->front]);
        for(i=p->front;i<p->rear;i++)
        {
            p->a[i]=p->a[i+1];
        }
        p->rear--;
    }
}
void peek(queue *p)
{
    if(p->rear==-1)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        int i;
        printf("\nQueue :\n");
        for(i=p->front;i<=p->rear;i++)
        {
            printf("%d\t",p->a[i]);
        }
        printf("\n");
    }
}
