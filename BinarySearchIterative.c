#include<stdio.h>
int Search(int * ,int ,int );
int main()
{
    printf("----> I Assume You Enter Sorted Array <----\n");
    int a[100],n,i,x,r;
    printf("Enter Number of Elements : ");
    scanf("%d",&n);
    printf("Enter %d Elements\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nEnter Element to be Searched : ");
    scanf("%d",&x);
    r=Search(a,n,x);
    if(r==-1)
        printf("\n%d Not Found\n",x);
    else
        printf("\n%d Found at %d\n",x,r);
}
int Search(int *a,int n,int x)
{
    int first=0,last=n-1,mid;
    while(first<=last)
    {
        mid=(first+last)/2;
        if(a[mid]==x)
            return mid;
        else if(x<a[mid])
            last=mid-1;
        else
            first=mid+1;
    }
    return -1;
}
