#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int n, key, i;
    
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Seed random number generator
    srand(time(NULL));
    
    // Fill array with random numbers
    printf("Generated array: ");
    for(i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Random numbers between 0-99
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    printf("Enter number to search: ");
    scanf("%d", &key);

    clock_t start = clock();   // start time

    int found = 0;
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = 1;
            break;
        }
    }

    clock_t end = clock();     // end time

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if(found)
        printf("Element %d found at index %d\n", key, i);
    else
        printf("Element %d not found\n", key);

    printf("Time taken to search: %f seconds\n", time_taken);

    return 0;
}