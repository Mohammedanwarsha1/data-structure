#include<stdio.h>
void swap(int*x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partision(int a[],int l,int h)
{
    int pivot=a[l];
    int i=l,j=h;
    do
    {
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j)
        {
            swap(&a[i],&a[j]);
        }
    } while (i<j);
    swap(&a[l],&a[j]);
    return j;
}
void QuickSort(int a[],int l,int h)
{
    if(l<h)
    {
     int p=partision(a,l,h);
     QuickSort(a,l,p);
     QuickSort(a,p+1,h);
    }
}
int main()
{
    int a[]={8,7,6,5,4,3,2},n=7;
    int i;
    QuickSort(a,0,n-1);
    for(i=0;i<n;i++)
     printf("%d",a[i]);
    printf("\n");
    return 0;
}