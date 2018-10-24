#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int info;
    struct Node *next;
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
void count();
void search();
int main()
{
    int c;
    init();
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
                insertbeg();
                break;
            case 2:
                insertlast();
                break;
            case 3:
                insertmid();
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
                deletebeg();
                break;
            case 2:
                deletelast();
                break;
            case 3:
                deletemid();
                break;
            default :
                printf("\nInvalid Choice\n");
            }
            break;
        case 3:
            display();
            break;
        case 4:
            count();
            break;
        case 5:
            search();
            break;
        case 6:
            exit(0);
        default :
            printf("\nEnter a Valid Choice\n");
        }
    }
    return 0;
}
void init()
{
    int n;
    printf("\nEnter Number of Nodes to be Inserted : ");
    scanf("%d",&n);
    if(n>0)
    {
        int i,data;
        Node *newnode;
        for(i=0;i<n;i++)
        {
            newnode=(Node *)malloc(sizeof(Node));
            printf("\nEnter Data to be Inserted : ");
            scanf("%d",&data);
            newnode->info=data;
            newnode->next=NULL;
            if(head==NULL)
            {
                head=newnode;
                temp=head;
            }
            else
            {
                temp->next=newnode;
                temp=newnode;
            }
        }
    }
    printf("\n");
}
void display()
{
    if(head==NULL)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        printf("\nLinked List : ");
        for(temp=head;temp!=NULL;temp=temp->next)
            printf("%d ",temp->info);
        printf("\n");
    }
}
void insertbeg()
{
    int data;
    Node *newnode;
    newnode=(Node *)malloc(sizeof(Node));
    printf("\nEnter Data to be Inserted : ");
    scanf("%d",&data);
    newnode->info=data;
    newnode->next=head;
    head=newnode;
    printf("\n");
}
void insertlast()
{
    if(head==NULL)
    {
        insertbeg();
    }
    else
    {
        int data;
        for(temp=head;temp->next!=NULL;temp=temp->next);
        Node *newnode;
        newnode=(Node *)malloc(sizeof(Node));
        printf("\nEnter Data to be Inserted : ");
        scanf("%d",&data);
        newnode->info=data;
        newnode->next=NULL;
        temp->next=newnode;
        printf("\n");
    }
}
void insertmid()
{
    int pos;
    printf("\nEnter Position : ");
    scanf("%d",&pos);
    printf("\n");
    if(head==NULL || pos ==0)
    {
        insertbeg();
    }
    else
    {
        int data;
        Node *newnode;
        newnode=(Node *)malloc(sizeof(Node));
        printf("\nEnter Data to be Inserted : ");
        scanf("%d",&data);
        newnode->info=data;
        newnode->next=NULL;
        int i;
        temp=head;
        for(i=0;i<pos-1;i++)
            temp=temp->next;
        newnode->next=temp->next;
        temp->next=newnode;
        printf("\n");
    }
}
void deletelast()
{
    if(head==NULL)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        Node *prev;
        for(temp=head;temp->next!=NULL;temp=temp->next)
            prev=temp;
        printf("\nDeleted : %d\n",temp->info);
        prev->next=NULL;
        free(temp);
    }
}
void deletebeg()
{
    if(head==NULL)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        printf("\nDeleted %d\n",head->info);
        temp=head;
        head=head->next;
        free(temp);
    }
}
void deletemid()
{
    if(head==NULL)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        int data,flag=0;
        Node *prev;
        printf("\nEnter Data to be Deleted : ");
        scanf("%d",&data);
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            if(data==temp->info)
            {
                printf("\nDeleted: %d\n",temp->info);
                prev->next=temp->next;
                free(temp);
                flag=1;
                break;
            }
            prev=temp;
        }
        if(flag==0)
        {
            printf("\nElement Not Found\n");
        }
    }
}
void count()
{
    int i=0;
    for(temp=head;temp!=NULL;temp=temp->next)
        i++;
    printf("\nLinked List Contains %d Nodes\n",i);
}
void search()
{
    int data,i=0,flag=0;
    printf("\nEnter Element to be Searched : ");
    scanf("%d",&data);
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        if(data==temp->info)
        {
            printf("Found %d at %d\n",data,i);
            flag=1;
        }
        i++;
    }
    if(flag==0)
    {
        printf("\nNot Found\n");
    }
}
