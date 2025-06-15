#include <stdio.h>
void generateFibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm,i;
    printf("Fibonacci Sequence: %d, %d", t1, t2);
    for (i = 3; i <= n; ++i) {
        nextTerm = t1 + t2;
        printf(", %d", nextTerm);
        t1 = t2;
        t2 = nextTerm;
    }
}
int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Please enter a positive integer.\n");
    } else if (n == 1) {
        printf("Fibonacci Sequence: 0\n");
    } else {
        generateFibonacci(n);
    }
    printf("\nName:Cosmic Gautam\nRoll no.:07");
    return 0;
}

