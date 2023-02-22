#include<stdio.h>
void swap(int*x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void selectionSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=a[i];
        int index=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
             min=a[j];
             index=j;
            }
        }
        swap(&a[i],&a[index]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}
int main()
{
    int a[100],n;
    printf("enter the array size");
    scanf("%d",&n);
    printf("enter the array elements");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selectionSort(a,n);
}