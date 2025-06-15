#include <stdio.h>
#include <stdlib.h>

// Function to return the maximum value that can be put in a knapsack of capacity W
int knapsackRec(int W, int *val, int *wt, int n) {
    // Base Case
    if (n == 0 || W == 0)
        return 0;

    int pick = 0;

    // Pick nth item if it does not exceed the capacity of knapsack
    if (wt[n - 1] <= W)
        pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1);

    // Don't pick the nth item
    int notPick = knapsackRec(W, val, wt, n - 1);

    // Return the maximum of pick and notPick
    return (pick > notPick) ? pick : notPick;
}

// Wrapper function to calculate the maximum value in the knapsack
int knapsack(int W, int *val, int *wt, int n) {
    return knapsackRec(W, val, wt, n);
}

int main() {
    int val[] = {1, 2, 3};
    int wt[] = {4, 5, 1};
    int W = 4;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value in knapsack: %d\n", knapsack(W, val, wt, n));
        printf("\nName:Cosmic Gautam\tRollno.:07");

    return 0;
}
