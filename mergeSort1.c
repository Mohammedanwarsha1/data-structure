#include<stdio.h>
void merge(int a[],int lb,int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int b[100];
    while(i<=mid && j<=ub)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            k++;
            j++;
        }
    }
    if(i>mid)
    {
        while(j<ub)
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
    else{
        while(i<=mid)
        {
            b[k]=a[i];
            k++;
            i++;
        }
    }
    for(int k=lb;k<=ub;k++)
    {
        a[k]=b[k];
    }
}
void mergeSort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
int main()
{
    int a[100],n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    printf("enter the array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}