#include <stdio.h>
#include <stdlib.h>

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp) {
        if (exp % 2) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int millerTest(long long d, long long n) {
    long long a = 2 + rand() % (n - 4);
    long long x = power(a, d, n);
    if (x == 1 || x == n - 1) return 1;
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        if (x == 1) return 0;
        if (x == n - 1) return 1;
    }
    return 0;
}

int isPrime(long long n, int k) {
	int i;
    if (n < 2 || (n % 2 == 0 && n != 2)) return 0;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    for (i = 0; i < k; i++)
        if (!millerTest(d, n)) return 0;
    return 1;
}

int main() {
    long long n;
    printf("Enter a number: ");
    scanf("%lld", &n);
    printf(isPrime(n, 5) ? "Prime\n" : "Not Prime\n");
    	printf("\nName:Cosmic Gautam\tRoll no.:07");

    return 0;
}

