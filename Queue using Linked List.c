#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int info;
    struct queue *next;
}queue;
void enqueue(queue **);
void dequeue(queue **);
void display(queue **);
int main()
{
    int c;
    queue *front=NULL;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter a Choice : ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            enqueue(&front);
            break;
        case 2:
            dequeue(&front);
            break;
        case 3:
            display(&front);
            break;
        case 4:
            exit(0);
        default:
            printf("\nEnter a Valid Choice");
        }
    }
    return 0;
}
void enqueue(queue **f)
{
    int element;
    queue *newnode;
    newnode = (queue *)malloc(sizeof(queue));
    printf("Enter element to be Inserted : ");
    scanf("%d",&element);
    newnode->info=element;
    newnode->next=NULL;
    if(*f==NULL)
    {
        *f=newnode;
    }
    else
    {
        queue *temp;
        for(temp=*f;temp->next!=NULL;temp=temp->next);
        temp->next=newnode;
    }
}
void dequeue(queue **f)
{
    if(*f==NULL)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        queue *temp;
        temp=*f;
        *f=(*f)->next;
        printf("\nDeleted : %d",temp->info);
        free(temp);
    }
}
void display(queue **f)
{
    queue *temp;
    printf("\nQueue Contains : \n");
    for(temp=*f;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->info);
    }
}
