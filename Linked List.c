#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int info;
    struct Node *next;
}Node;
Node *temp;
void init(Node **);
void display(Node **);
void insertbeg(Node **);
void insertlast(Node **);
void insertmid(Node **);
void deletebeg(Node **);
void deletelast(Node **);
void deletemid(Node **);
void count(Node **);
void search(Node **);
int main()
{
    Node *head=NULL;
    init(&head);
    int c;
    while(1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Count Number of Nodes\n5.Search Element\n6.Exit\nEnter a Choice : ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("1.Insert at Beginning\n2.Insert at Last\n3.Insert at Position\nEnter a Choice : ");
            scanf("%d",&c);
            switch(c)
            {
            case 1:
                insertbeg(&head);
                break;
            case 2:
                insertlast(&head);
                break;
            case 3:
                insertmid(&head);
                break;
            default :
                printf("\nInvalid Choice\n");
            }
            break;
        case 2:
            printf("1.Delete at Beginning\n2.Delete at Last\n3.Delete an Element\nEnter a Choice : ");
            scanf("%d",&c);
            switch(c)
            {
            case 1:
                deletebeg(&head);
                break;
            case 2:
                deletelast(&head);
                break;
            case 3:
                deletemid(&head);
                break;
            default :
                printf("\nInvalid Choice\n");
            }
            break;
        case 3:
            display(&head);
            break;
        case 4:
            count(&head);
            break;
        case 5:
            search(&head);
            break;
        case 6:
            exit(0);
        default :
            printf("\nEnter a Valid Choice\n");
        }
    }
    return 0;
}
void init(Node **p)
{
    int n;
    printf("\nEnter number of Nodes : ");
    scanf("%d",&n);
    if(n==0)
    {
        return NULL;
    }
    else
    {
        int i;
        Node *newnode;
        for(i=0;i<n;i++)
        {
            int data;
            printf("\nEnter Element to be Inserted : ");
            scanf("%d",&data);
            newnode=(Node *)malloc(sizeof(Node));
            newnode->info=data;
            newnode->next=NULL;
            if(*p==NULL)
            {
                *p=newnode;
                temp=newnode;
            }
            else
            {
                temp->next=newnode;
                temp=newnode;
            }
        }
    }
}
void display(Node **p)
{
    printf("\nLinked List Contains : ");
    for(temp=*p;temp!=NULL;temp=temp->next)
        printf("%d ",temp->info);
    printf("\n");
}
void insertbeg(Node **p)
{
    Node *newnode;
    newnode=(Node *)malloc(sizeof(Node));
    int data;
    printf("\nEnter Element to be Inserted  : ");
    scanf("%d",&data);
    newnode->info=data;
    newnode->next=*p;
    *p=newnode;
}
void insertlast(Node **p)
{
    Node *newnode;
    newnode=(Node *)malloc(sizeof(Node));
    int data;
    printf("\nEnter Element to be Inserted  : ");
    scanf("%d",&data);
    newnode->info=data;
    newnode->next=NULL;
    for(temp=*p;temp->next!=NULL;temp=temp->next);
    temp->next=newnode;
}
void insertmid(Node **p)
{
    int data,pos,i;
    printf("\nEnter Element and Location : ");
    scanf("%d%d",&data,&pos);
    Node *newnode;
    temp=*p;
    newnode=(Node *)malloc(sizeof(Node));
    newnode->info=data;
    newnode->next=NULL;
    for(i=0;i<pos-1;i++)
        temp=temp->next;
    newnode->next=temp->next;
    temp->next=newnode;
}
void deletebeg(Node **p)
{
    if(*p==NULL)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        temp=*p;
        *p=(*p)->next;
        printf("\nDeleted %d\n",temp->info);
        free(temp);
    }
}
void deletelast(Node **p)
{
    if(*p==NULL)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        Node *prev;
        for(temp=*p;temp->next!=NULL;temp=temp->next)
            prev=temp;
        printf("\nDeleted %d\n",temp->info);
        free(temp);
        prev->next=NULL;
    }
}
void deletemid(Node **p)
{
    int data,flag=0;
    Node *prev;
    printf("\nEnter Data to be Deleted : ");
    scanf("%d",&data);
    for(temp=*p;temp!=NULL;temp=temp->next)
    {
        if(temp->info==data)
        {
            prev->next=temp->next;
            printf("\nDeleted %d\n",temp->info);
            free(temp);
            flag=1;
            break;
        }
        prev=temp;
    }
    if(flag==0)
    {
        printf("\nNot Found\n");
    }
}
void count(Node **p)
{
    int i=0;
    for(temp=*p;temp!=NULL;temp=temp->next)
        i++;
    printf("\nLinked List Contains %d Elements\n",i);
}
void search(Node **p)
{
    int flag=0,data,i=0;
    printf("\nEnter Element to be Searched : ");
    scanf("%d",&data);
    for(temp=*p;temp!=NULL;temp=temp->next)
    {
        if(temp->info==data)
        {
            flag=1;
            printf("Found at %d\n",i);
        }
        i++;
    }
    if(flag==0)
        printf("\nNot Found\n");
}
