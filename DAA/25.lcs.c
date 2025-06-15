#include <stdio.h>
#include <string.h>

// Function to return the length of LCS for s1[0..m-1], s2[0..n-1]
int lcsRec(char *s1, char *s2, int m, int n) {
    // Base case: If either string is empty, the length of LCS is 0
    if (m == 0 || n == 0)
        return 0;

    // If the last characters of both substrings match
    if (s1[m - 1] == s2[n - 1])
        // Include this character in LCS and recur for remaining substrings
        return 1 + lcsRec(s1, s2, m - 1, n - 1);
    else
        // If the last characters do not match
        // Recur for two cases:
        // 1. Exclude the last character of s1
        // 2. Exclude the last character of s2
        // Take the maximum of these two recursive calls
        return (lcsRec(s1, s2, m, n - 1) > lcsRec(s1, s2, m - 1, n)) 
               ? lcsRec(s1, s2, m, n - 1) 
               : lcsRec(s1, s2, m - 1, n);
}

// Wrapper function to calculate the length of LCS
int lcs(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    return lcsRec(s1, s2, m, n);
}

int main() {
    char s1[] = "COSMIC";
    char s2[] = "GAUTAM";

    printf("Length of LCS is %d\n", lcs(s1, s2));
        printf("\nName:Cosmic Gautam\tRollno.:07");


    return 0;
}
