#include<stdio.h>
int binarysearch(int a[],int n,int key)
{
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]==key)
         return mid;
        else if(a[mid]<key)
         s=mid-1;
        else
         e=mid-1;
    }
    return -1;
}
int main()
{
    int a[100],n,k;
    printf("enter the size of array");
    scanf("%d",&n);
    printf("enter the key element");
    scanf("%d",&k);
    printf("enter the array elements");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int m=binarysearch(a,n,k);
    if(m!=-1)
    {
        printf("element found at index %d",m);
    }
    else{
        printf("element not found");
    }
    return 0;
}