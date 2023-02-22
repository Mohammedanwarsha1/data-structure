#include<stdio.h>
void bubblesort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
     for(j=0;j<n-i-1;j++)
     { 
        if(arr[j]>arr[j+1])
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
     }
}
void print(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
     printf("%d ",arr[i]);
}
int main()
{
    int a[50],n;
    printf("\nenter the number of elements in array");
    scanf("%d",&n);
    printf("\nenter the elements in array");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubblesort(a,n);
    print(a,n);
}