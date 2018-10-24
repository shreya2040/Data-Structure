#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
typedef struct queue
{
    int info;
    struct queue *next;
}queue;
queue *front=NULL,*temp;
int main()
{
    int c;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter a Choice : ");
        scanf("%d",&c);
        switch(c)
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
        default:
            printf("\nEnter a Valid Choice");
        }
    }
    return 0;
}
void enqueue()
{
    int element;
    queue *newnode;
    newnode = (queue *)malloc(sizeof(queue));
    printf("Enter element to be Inserted : ");
    scanf("%d",&element);
    newnode->info=element;
    newnode->next=NULL;
    if(front==NULL)
    {
        front=newnode;
    }
    else
    {
        for(temp=front;temp->next!=NULL;temp=temp->next);
        temp->next=newnode;
    }
}
void dequeue()
{
    if(front==NULL)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        temp=front;
        front=front->next;
        printf("\nDeleted : %d",temp->info);
        free(temp);
    }
}
void display()
{
    printf("\nQueue Contains : \n");
    for(temp=front;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->info);
    }
}
