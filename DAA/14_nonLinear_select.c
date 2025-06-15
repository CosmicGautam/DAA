#include<stdio.h>
#define MAX 100

int Select_NonLinear(int a[], int k, int n) {
    int i, j, temp, min;
    for(i = 0; i < k; i++) {
        min = i;
        for(j = i + 1; j < n; j++) {
            if(a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    return a[k - 1];
}
int main() {
    int a[MAX], n, i, k, kthSmallest;
    printf("Enter the number of Data item: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    printf("Enter the position to find: ");
    scanf("%d", &k);
    kthSmallest = Select_NonLinear(a, k, n);
    printf("%dth smallest: %d\n", k, kthSmallest);
    return 0;
}

