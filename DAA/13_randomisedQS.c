#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void Randomised_QS(int[], int, int);
int Randomised_partition(int[], int, int);
int partition(int[], int, int);

int main() {
    int a[MAX], n, i;

    printf("Enter the number of Data items: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    Randomised_QS(a, 0, n - 1);

    printf("\nData after sorting: ");
    for (i = 0; i < n; ++i)
        printf("%d ", a[i]);

    printf("\nName: Cosmic Gautam \nRoll no.:07");

    return 0;
}

void Randomised_QS(int a[], int l, int r) {
    int j;
    if (l < r) {
        j = Randomised_partition(a, l, r);
        Randomised_QS(a, l, j - 1);
        Randomised_QS(a, j + 1, r);
    }
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
