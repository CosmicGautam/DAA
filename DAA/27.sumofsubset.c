#include <stdio.h>
#include <stdlib.h>

// Global flag to check if any subset is found
int flag = 0;

// Function to print all subsets with the given sum
void PrintSubsetSum(int i, int n, int set[], int targetSum, int subset[], int subsetSize) {
    // If targetSum is zero, then a valid subset is found
    if (targetSum == 0) {
    	int j;
        // Print the subset
        flag = 1;
        printf("[ ");
        for (j = 0; j < subsetSize; j++) {
            printf("%d ", subset[j]);
        }
        printf("]");
        return;
    }

    // If we have reached the end of the array, return
    if (i == n) {
        return;
    }

    // Not considering the current element
    PrintSubsetSum(i + 1, n, set, targetSum, subset, subsetSize);

    // Consider the current element if it is less than or equal to targetSum
    if (set[i] <= targetSum) {
        // Add the current element to the subset
        subset[subsetSize] = set[i];

        // Recursive call for considering the current element
        PrintSubsetSum(i + 1, n, set, targetSum - set[i], subset, subsetSize + 1);
    }
}

// Driver code
int main() {
    // Test case 1
    int set1[] = {1, 2, 1};
    int sum1 = 3;
    int n1 = sizeof(set1) / sizeof(set1[0]);
    int subset1[n1]; // Temporary array to store subsets
    printf("Output 1:\n");
    PrintSubsetSum(0, n1, set1, sum1, subset1, 0);
    printf("\n");
    flag = 0;

    // Test case 2
    int set2[] = {3, 34, 4, 12, 5, 2};
    int sum2 = 30;
    int n2 = sizeof(set2) / sizeof(set2[0]);
    int subset2[n2]; // Temporary array to store subsets
    printf("Output 2:\n");
    PrintSubsetSum(0, n2, set2, sum2, subset2, 0);
    if (!flag) {
        printf("There is no such subset");
    }
	printf("\nName:Cosmic Gautam	Rollno.:07");
    return 0;
}
