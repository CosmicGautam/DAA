#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int Randomised_Select(int[], int, int,int);
int Randomised_partition(int[], int, int);
int partition(int[], int, int);

int main() {
   int a[MAX], n, i, k, kthSmallest;
    printf("Enter the number of Data item: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    printf("Enter the position to find: ");
    scanf("%d", &k);
    kthSmallest = Randomised_Select(a, 0, n-1,k);
    printf("%dth smallest: %d\n", k, kthSmallest);
    printf("\nName: Cosmic Gautam \nRoll no.:07");
	return 0;
}

int Randomised_Select(int a[], int l, int r,int i) {
    int p,k;
   if(l==r)
    return a[l];
    p=Randomised_partition(a,l,r);
    k=p-l+1;

    if(i<=k)
        return Randomised_Select(a,l,p-1,i);
    else
        return Randomised_Select(a,p+1,r,i-k);

}

int Randomised_partition(int a[], int l, int r) {
    int k, temp;
    srand(time(NULL));
    k = rand() % (r - l + 1) + l;
    temp = a[k];
    a[k] = a[l];
    a[l] = temp;
    return partition(a, l, r);
}

int partition(int a[], int l, int r) {
    int pivot, i, j, temp;
    pivot = a[l];
    i = l;
    for (j = i + 1; j <= r; j++) {
        if (a[j] <= pivot) {
            i++;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    temp = a[l];
    a[l] = a[i];
    a[i] = temp;

    return i;
}
