#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int find_median(int arr[], int n) {
    // Simple bubble sort for small arrays
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    return arr[n/2];
}
int median_of_medians(int arr[], int n) {
    if (n <= 5) {
        return find_median(arr, n);
    }
    int num_groups = (n + 4) / 5; // Ceiling division
    int medians[num_groups];
    
    for (int i = 0; i < num_groups; i++) {
        int group_start = i * 5;
        int group_size = (group_start + 5 <= n) ? 5 : n - group_start;
        int group[group_size];
        for (int j = 0; j < group_size; j++) {
            group[j] = arr[group_start + j];
        }
        medians[i] = find_median(group, group_size);
    }
    return median_of_medians(medians, num_groups);
}

// Partition function similar to quicksort
int partition(int arr[], int low, int high, int pivot) {
    // Find the pivot element and swap it to the end
    int pivot_index;
    for (pivot_index = low; pivot_index <= high; pivot_index++) {
        if (arr[pivot_index] == pivot) {
            break;
        }
    }
    swap(&arr[pivot_index], &arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i + 1;
}
int randomized_select(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }
    int n = high - low + 1;
    int subarray[n];
    for (int i = 0; i < n; i++) {
        subarray[i] = arr[low + i];
    }
    int pivot = median_of_medians(subarray, n);
    int pivot_index = partition(arr, low, high, pivot);
    int left_size = pivot_index - low + 1;
    if (k == left_size) {
        return arr[pivot_index];
    } else if (k < left_size) {
        return randomized_select(arr, low, pivot_index - 1, k);
    } else {
        return randomized_select(arr, pivot_index + 1, high, k - left_size);
    }
}

int main() {
    int k;
    int arr[5];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position of the element to select: ");
    scanf("%d", &k);
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int result = randomized_select(arr, 0, n - 1, k);
    printf("The %dth smallest element is: %d\n", k, result);
    printf("Name: Cosmic Gautam\n");
    printf("Roll no.: 07\n");
    return 0;
}