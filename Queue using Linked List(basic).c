#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int info;
    struct queue *next;
}Queue;
Queue *Front = NULL,*Rear = NULL;
void enqueue();
void dequeue();
void display();
int main()
{
    int i;
    while(1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter Choice : ");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
void display()
{
    if(Front==NULL)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        Queue *temp;
        printf("\nQueue : \n");
        for(temp=Front;temp!=NULL;temp=temp->next)
        {
            printf("%d ",temp->info);
        }
        printf("\n");
    }
}
void enqueue()
{
    Queue *newnode;
    newnode = (Queue *)malloc(sizeof(Queue));
    newnode->next=NULL;
    printf("\nEnter Data to be Inserted : ");
    int data;
    scanf("%d",&data);
    newnode->info=data;
    if(Front==NULL)
    {
        Front=newnode;
        Rear=newnode;
    }
    else
    {
        Rear->next=newnode;
        Rear=newnode;
    }
}
void dequeue()
{
    if(Front==NULL)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        Queue *temp = Front;
        Front=Front->next;
        printf("\nDequeued %d\n",temp->info);
        free(temp);
    }
}
