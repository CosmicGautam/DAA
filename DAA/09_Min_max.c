#include <stdio.h>
#define MAX 100

// Function to find the minimum and maximum values in an aay using divide and conquer
void findMinMax(int a[], int l, int r, int *min, int *max) {
    int min1, max1, min2, max2;

    // Base case: only one element
    if (l == r) {
        *min = a[l];
        *max = a[l];
        return;
    }

    // Base case: only two elements
    if (r == l + 1) {
        if (a[l] < a[r]) {
            *min = a[l];
            *max = a[r];
        } else {
            *min = a[r];
            *max = a[l];
        }
        return;
    }

    // Recursive case: more than two elements
    int mid = (l + r) / 2;

    findMinMax(a, l, mid, &min1, &max1);
    findMinMax(a, mid + 1, r, &min2, &max2);

    // Combine results
    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}

int main() {
    int i,n,min,max,a[MAX];
    printf("Enter then size of list: ");
    scanf("%d",&n);
    printf("\nEnter the content of list : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }


    findMinMax(a, 0,n-1, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
    printf("\nName: Cosmic Gautam \nRoll no.:07");
    return 0;
}
