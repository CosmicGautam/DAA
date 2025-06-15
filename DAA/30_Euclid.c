
#include <stdio.h>
// Function to compute GCD using the Euclidean algorithm
int gcd(int a, int b) {
// Ensure a is greater than or equal to b
while (b != 0) {
int temp = b;
b = a % b;
a = temp;
}
return a;
}
int main() {
int a, b;
printf("Enter two integers: ");
scanf("%d %d", &a, &b);
printf("The GCD of %d and %d is %d\n", a, b, gcd(a, b));
printf("Name:Cosmic Gautam\tRoll no.:07");
return 0;
}