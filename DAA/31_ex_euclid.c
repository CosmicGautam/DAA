#include <stdio.h>
int euclidean(int a, int b, int *x, int *y) {
    // Base case
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1; // To store results of recursive call
    int gcd = euclidean(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int main() {
    int a, b, x, y;
    printf("Enter two integers a and b: ");
    scanf("%d %d", &a, &b);
    int gcd = euclidean(a, b, &x, &y);
    printf("Coefficients (x, y) such that %d*%d + %d*%d = %d are: (%d, %d)\n", a, x, b, y, gcd, x, y);
	printf("\nName:Cosmic Gautam\tRoll no.:07");
    return 0;
}
