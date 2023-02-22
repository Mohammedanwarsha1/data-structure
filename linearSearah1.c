#include<stdio.h>

int linearSearch(int a[],int n,int key)
{

    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            return i+1;
        }
    }
}
int main()
{
    int n,k;
    int a[50];
    printf("enter the size of array");
    scanf("%d",&n);
    printf("enter the array elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the key");
    scanf("%d",&k);
    int m=linearSearch(a,n,k);
    if(m)
    {
        printf("element found at index %d",m);
    }
    else{
        printf("element not found");
    }

}