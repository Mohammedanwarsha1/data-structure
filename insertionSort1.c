#include<stdio.h>
void insertionSort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int element=a[i];
        int j=i-1;
        while(j>=0 && a[j]>element) 
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=element;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}
int main()
{
    int a[100],n;
    printf("enter the size of the array");
    scanf("%d",&n);
    printf("enter the array elements");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertionSort(a,n);
}