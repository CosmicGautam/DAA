#include <stdio.h>
#define MAX 100

void heapSort(int A[], int n);
void buildMaxHeap(int A[], int n);
void maxHeapify(int A[], int i, int n);
void swap(int *a, int *b);

int main() {
   int A[MAX],n,i,j,temp;
    printf("Enter the number of Data item: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;++i)
        scanf("%d",&A[i]);
    heapSort(A,n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("\nName: Cosmic Gautam \nRoll no.:07");
    return 0;
}

void heapSort(int A[], int n) {
	int i;
    buildMaxHeap(A, n);
    for (i = n - 1; i >= 1; i--) {
        swap(&A[0], &A[i]);
        maxHeapify(A, 0, i);
    }
}

void buildMaxHeap(int A[], int n) {
	int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(A, i, n);
    }
}

void maxHeapify(int A[], int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != i) {
        swap(&A[i], &A[largest]);
        maxHeapify(A, largest, n);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
