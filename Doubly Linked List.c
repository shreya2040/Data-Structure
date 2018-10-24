#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *prev;
    struct node *next;
}Node;
Node *head=NULL,*tail=NULL,*temp;
void init();
void displaystart();
void displayend();
void insertbeg();
void insertlast();
void insertmid();
void deletebeg();
void deletelast();
void deletemid();
void search();
int main()
{
    int c;
    init();
    while(1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\nEnter a Choice : ");
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
            printf("1.Display from Start\n2.Display from End\nEnter a Choice : ");
            scanf("%d",&c);
            switch(c)
            {
            case 1:
                displaystart();
                break;
            case 2:
                displayend();
            }
            break;
        case 4:
            search();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nEnter a Valid Choice\n");
        }
    }
    return 0;
}
void init()
{
    int n;
    printf("Enter number of Node : ");
    scanf("%d",&n);
    if(n>0)
    {
        int i,e;
        Node *newnode;
        for(i=0;i<n;i++)
        {
            printf("\nEnter Element to be Inserted : ");
            scanf("%d",&e);
            newnode=(Node *)malloc(sizeof(Node));
            newnode->info=e;
            newnode->prev=NULL;
            newnode->next=NULL;
            if(head==NULL)
            {
                head=newnode;
                temp=newnode;
            }
            else
            {
                temp->next=newnode;
                newnode->prev=temp;
                temp=newnode;
            }
        }
        tail=temp;
    }
}
void displaystart()
{
    if(head==NULL)
    {
        printf("\nUnDeRfLoW\n");
    }
    else
    {
        printf("\nDoubly Linked List : ");
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            printf("%d ",temp->info);
        }
        printf("\n");
    }
}
void displayend()
{
    if(tail==NULL)
    {
        printf("\nUnDeRfLoW\n");
    }
    else
    {
        printf("\nDoubly Linked List : ");
        for(temp=tail;temp!=NULL;temp=temp->prev)
        {
            printf("%d ",temp->info);
        }
        printf("\n");
    }
}
void insertbeg()
{
    int e;
    Node *newnode;
    printf("\nEnter Element to be Inserted : ");
    scanf("%d",&e);
    newnode=(Node *)malloc(sizeof(Node));
    newnode->info=e;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
}
void insertlast()
{
    int e;
    Node *newnode;
    printf("\nEnter Element to be Inserted : ");
    scanf("%d",&e);
    newnode=(Node *)malloc(sizeof(Node));
    newnode->info=e;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=newnode;
        tail=head;
    }
    else
    {
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
}
void insertmid()
{
    int e,pos;
    Node *newnode;
    printf("\nEnter Element to be Inserted : ");
    scanf("%d",&e);
    printf("\nEnter Position : ");
    scanf("%d",&pos);
    newnode=(Node *)malloc(sizeof(Node));
    newnode->info=e;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=newnode;
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
        newnode->prev=temp;
        temp->next->prev=newnode;
        temp->next=newnode;
    }
}
void deletebeg()
{
    if(head==NULL)
    {
        printf("\nUnDeRfLoW\n");
    }
    else
    {
        if(head==tail)
        {
            temp=head;
            printf("Deleted : %d\n",temp->info);
            free(temp);
            head=NULL;
            tail=NULL;
        }
        else
        {
            temp=head;
            head=head->next;
            head->prev=NULL;
            printf("Deleted : %d\n",temp->info);
            free(temp);
        }
    }
}
void deletelast()
{
    if(head==NULL)
    {
        printf("\nUnDeRfLoW\n");
    }
    else
    {
        if(tail==head)
        {
            temp=tail;
            printf("Deleted : %d\n",temp->info);
            free(temp);
            tail=NULL;
            head=NULL;
        }
        else
        {
            temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            printf("Deleted : %d\n",temp->info);
            free(temp);
        }
    }
}
void deletemid()
{
    if(head==NULL)
    {
        printf("\nUnDeRfLoW\n");
    }
    else
    {
        int e,flag=0;
        printf("\nEnter Element to be Deleted : ");
        scanf("%d",&e);
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            if(temp->info==e)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("\nNoT FoUnD\n");
        }
        else
        {
            if(temp==head)
            {
                deletebeg();
            }
            else if(temp==tail)
            {
                deletelast();
            }
            else
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                printf("Deleted : %d\n",temp->info);
            }
        }
    }
}
void search()
{
    int i=0,e,flag=0;
    printf("\nEnter Element to be Searched : ");
    scanf("%d",&e);
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        if(temp->info==e)
        {
            printf("Found at : %d\n",i);
            flag=1;
        }
        i++;
    }
    if(flag==0)
        printf("\nNoT FoUnD\n");
}
