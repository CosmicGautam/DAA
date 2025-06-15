#include <stdio.h>
#include <stdlib.h>

// Function to check if it is safe to place
// the queen at board[row][col]
int isSafe(int **mat, int row, int col, int n) {
    int i, j;

    // Check this col on upper side
    for (i = 0; i < row; i++)
        if (mat[i][col])
            return 0;

    // Check upper diagonal on left side
    for (i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j])
            return 0;

    // Check lower diagonal on left side
    for (i = row-1, j = col+1; j < n && i >= 0; i--, j++)
        if (mat[i][j])
            return 0;

    return 1;
}

int placeQueens(int row, int **mat, int n) {
    // base case: If all queens are placed
    // then return true
    int i;
    if (row == n) return 1;

    // Consider the row and try placing
    // queen in all columns one by one
    for (i = 0; i < n; i++) {
        // Check if the queen can be placed
        if (isSafe(mat, row, i, n)) {
            mat[row][i] = 1;
            if (placeQueens(row + 1, mat, n))
                return 1;
            mat[row][i] = 0;
        }
    }
    return 0;
}

// Function to find the solution
// to the N-Queens problem
int* nQueen(int n, int* returnSize) {
	int i,j;
    // Initialize the board
    int **mat = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        mat[i] = (int *)calloc(n, sizeof(int));

    // If the solution exists
    if (placeQueens(0, mat, n)) {
        // to store the columns of the queens
        int *ans = (int *)malloc(n * sizeof(int));
        int index = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (mat[i][j]) {
                    ans[index++] = j + 1;
                }
            }
        }
        *returnSize = n;
        // Free the allocated memory for the board
        for (i = 0; i < n; i++)
            free(mat[i]);
        free(mat);
        return ans;
    } else {
        *returnSize = 1;
        int *ans = (int *)malloc(sizeof(int));
        ans[0] = -1;
        // Free the allocated memory for the board
        for (i = 0; i < n; i++)
            free(mat[i]);
        free(mat);
        return ans;
    }
}

int main() {
    int i,n;
    printf("Enter the size:");
    scanf("%d",&n);
    int returnSize;
    int *ans = nQueen(n, &returnSize);
    for (i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }
    free(ans);
    	printf("\nName:Cosmic Gautam	Rollno.:07");

    return 0;
}
