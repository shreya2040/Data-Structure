#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}Node;
Node *head=NULL,*temp;
void init();
void display();
void insertbeg();
void insertlast();
void insertmid();
void deletebeg();
void deletelast();
void deletemid();
void search();
void count();
int main()
{
    int c;
    init();
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Count\n6.Exit\nEnter a Choice : ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("1.Insert at Beginning\n2.Insert at Last\n3.Insert at Position\nEnter a Choice : ");
            scanf("%d",&c);
            switch(c)
            {
            case 1:
                insertbeg();
                break;
            case 2:
                insertlast();
                break;
            case 3:
                insertmid();
                break;
            }
            break;
        case 2:
            printf("1.Delete at Beginning\n2.Delete at Last\n3.Delete an Element\nEnter a Choice : ");
            scanf("%d",&c);
            switch(c)
            {
            case 1:
                deletebeg();
                break;
            case 2:
                deletelast();
                break;
            case 3:
                deletemid();
                break;
            }
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            count();
            break;
        case 6:
            exit(0);
        default :
            printf("\nInvalid Choice");
        }
    }
    return 0;
}
void init()
{
    int n;
    printf("\nEnter Number of Nodes : ");
    scanf("%d",&n);
    if(n>0)
    {
        int i,e;
        Node *newnode;
        for(i=0;i<n;i++)
        {
            newnode=(Node *)malloc(sizeof(Node));
            printf("Enter Data to be Inserted : ");
            scanf("%d",&e);
            newnode->info=e;
            newnode->next=head;
            if(head==NULL)
            {
                head=newnode;
                newnode->next=head;
                temp=head;
            }
            else
            {
                temp->next=newnode;
                temp=newnode;
            }
        }
    }
}
void display()
{
    if(head==NULL)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        printf("\nCircular Linked List : ");
        for(temp=head;temp->next!=head;temp=temp->next)
            printf("%d ",temp->info);
        printf("%d\n",temp->info);
    }
}
void insertbeg()
{
    int e;
    printf("\nEnter Data to be Inserted : ");
    scanf("%d",&e);
    Node *newnode;
    newnode=(Node *)malloc(sizeof(Node));
    newnode->info=e;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=newnode;
    }
    else
    {
        for(temp=head;temp->next!=head;temp=temp->next);
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
    }
}
void insertlast()
{
    int e;
    printf("\nEnter Data to be Inserted : ");
    scanf("%d",&e);
    Node *newnode;
    newnode=(Node *)malloc(sizeof(Node));
    newnode->info=e;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=newnode;
    }
    else
    {
        for(temp=head;temp->next!=head;temp=temp->next);
        newnode->next=head;
        temp->next=newnode;
    }
}
void insertmid()
{
    int e,pos;
    printf("\nEnter Data to be Inserted : ");
    scanf("%d",&e);
    printf("\nEnter Position : ");
    scanf("%d",&pos);
    Node *newnode;
    newnode=(Node *)malloc(sizeof(Node));
    newnode->info=e;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=newnode;
    }
    else
    {
        int i;
        temp=head;
        for(i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void deletebeg()
{
    if(head==NULL)
        printf("\nuNdErFlOw\n");
    else if(head->next==head)
    {
        printf("Deleted : %d",head->info);
        free(head);
        head=NULL;
    }
    else
    {
        Node *p;
        temp=head;
        head=head->next;
        printf("Deleted : %d",temp->info);
        for(p=temp;p->next!=temp;p=p->next);
        p->next=head;
        free(temp);
    }
}
void deletelast()
{
    Node *prev;
    if(head==NULL)
        printf("\nuNdErFlOw\n");
    else if(head->next==head)
    {
        printf("Deleted : %d\n",head->info);
        free(head);
        head=NULL;
    }
    else
    {
        for(temp=head;temp->next!=head;temp=temp->next)
            prev=temp;
        printf("Deleted %d\n",temp->info);
        prev->next=head;
        free(temp);
    }
}
void deletemid()
{
    int n,flag=0;
    Node *prev;
    printf("\nEnter Element to be Deleted : ");
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("\nUnDeRfLoW\n");
    }
    else
    {
        for(temp=head;temp->next!=head;temp=temp->next)
        {
            if(temp->info==n)
            {
                flag=1;
                prev->next=temp->next;
                printf("Deleted : %d",temp->info);
                free(temp);
                break;
            }
            prev=temp;
        }
        if(flag==0)
            printf("\nNot Found\n");
    }
}
void search()
{
    if(head==NULL)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        int e,i=1,flag=0;
        printf("\nEnter Element to be Searched : ");
        scanf("%d",&e);
        temp=head;
        do
        {
            if(temp->info==e)
            {
                printf("Found %d at %d",temp->info,i);
                flag=1;
            }
            temp=temp->next;
            i++;
        }while(temp!=head);
        if(flag!=1)
        {
            printf("\nNot Found\n");
        }
    }
}
void count()
{
    if(head==NULL)
    {
        printf("\nCircular Linked List Contains 0 Nodes\n");
    }
    else
    {
        int i=0;
        temp=head;
        do
        {
            temp=temp->next;
            i++;
        }while(temp!=head);
        printf("\nCircular Linked List Contains %d Nodes\n",i);
    }
}
