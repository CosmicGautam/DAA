#include <stdio.h>
#include <limits.h>

// Function to calculate the minimum number of multiplications needed
int minMultRec(int arr[], int i, int j) {

    // If there is only one matrix
    if (i + 1 == j)
        return 0;

    int res = INT_MAX;
	int k;
    // Place the first bracket at different positions
    // and recursively compute the minimum cost
    for (k = i + 1; k < j; k++) {
        int curr = minMultRec(arr, i, k) + 
                   minMultRec(arr, k, j) + 
                   arr[i] * arr[k] * arr[j];

        if (curr < res)
            res = curr;
    }

    // Return the minimum count
    return res;
}

int matrixMultiplication(int arr[], int n) {
    return minMultRec(arr, 0, n - 1);
}

int main() {
    int arr[] = {5, 10, 15, 30, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of multiplications is %d\n", matrixMultiplication(arr, n));
        printf("\nName:Cosmic Gautam	Rollno.:07");

    return 0;
}
