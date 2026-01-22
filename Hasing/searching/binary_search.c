#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to perform binary search
// Returns the index if element is found, otherwise returns -1
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;  // Element found
        } else if (arr[mid] < target) {
            left = mid + 1;  // Search in right half
        } else {
            right = mid - 1;  // Search in left half
        }
    }
    return -1;  // Element not found
}

int main() {
    int n, target;
    clock_t start, end;
    double cpu_time_used;
    
    // Input: size of array
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    // Create array
    int arr[n];
    
    // Generate random elements in array
    printf("\nGenerating %d random integers...\n", n);
    srand(time(0));  // Seed for random number generation
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000 + 1;  // Random numbers between 1 and 1000
    }
    
    // Display some elements before sorting
    printf("First 10 elements (before sort): ");
    for (int i = 0; i < (n < 10 ? n : 10); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Sort the array (required for binary search)
    printf("Sorting array...\n");
    qsort(arr, n, sizeof(int), compare);
    
    // Display some elements after sorting
    printf("First 10 elements (after sort): ");
    for (int i = 0; i < (n < 10 ? n : 10); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Pick a random element from the array to search
    int randomIndex = rand() % n;
    target = arr[randomIndex];
    printf("\nSearching for element: %d (from index %d)\n", target, randomIndex);
    
    // Start timing
    start = clock();
    
    // Perform binary search
    int result = binarySearch(arr, n, target);
    
    // End timing
    end = clock();
    
    // Calculate time required
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Display result
    printf("\n===== SEARCH RESULTS =====\n");
    if (result != -1) {
        printf("Status: Element FOUND\n");
        printf("Index: %d\n", result);
        printf("Position: %d\n", result + 1);
    } else {
        printf("Status: Element NOT FOUND\n");
    }
    
    printf("\n===== TIME ANALYSIS =====\n");
    printf("Array size (n): %d\n", n);
    printf("Time required: %e seconds\n", cpu_time_used);
    printf("Time required: %f milliseconds\n", cpu_time_used * 1000);
    
    return 0;
}
