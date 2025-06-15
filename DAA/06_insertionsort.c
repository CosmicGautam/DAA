
#include <stdio.h>
#define MAX 100
void insertionSort(int arr[],int n)
{
    int i,j,temp;
    for (i = 1 ; i<n; i++)
    {
        temp=arr[i];
        j=i-1;
        while ( j>=0 && arr[j] > temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
int main()
{
    int a[MAX],n,i;
    printf("Enter the number of Data item: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;++i)
        scanf("%d",&a[i]);
    insertionSort(a,n);
    printf("\nData after sorting: ");
    for(i=0;i<n;++i)
        printf("%d ",a[i]);

    printf("\nName: Cosmic Gautam \nRoll no.:07");


    return 0;

}
