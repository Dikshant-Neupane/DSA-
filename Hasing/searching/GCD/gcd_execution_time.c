#include<stdio.h>
#include<time.h>

int recursion(int a, int b){
    if (b == 0){
        return a;
    }
    return recursion(b, a % b);
}

int iteration(int a, int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int num1, num2;
    clock_t start, end;
    double time_recursion, time_iteration;
    
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    
    // Make sure inputs are positive
    num1 = num1 < 0 ? -num1 : num1;
    num2 = num2 < 0 ? -num2 : num2;
    
    // Measure execution time for recursion
    start = clock();
    int result_recursion = recursion(num1, num2);
    end = clock();
    time_recursion = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Measure execution time for iteration
    start = clock();
    int result_iteration = iteration(num1, num2);
    end = clock();
    time_iteration = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Display results
    printf("\n--- Results ---\n");
    printf("GCD using Recursion: %d\n", result_recursion);
    printf("Execution time (Recursion): %f seconds\n", time_recursion);
    printf("\nGCD using Iteration: %d\n", result_iteration);
    printf("Execution time (Iteration): %f seconds\n", time_iteration);
    
    // Compare performance
    if (time_recursion < time_iteration) {
        printf("\nRecursion is faster by %f seconds\n", time_iteration - time_recursion);
    } else if (time_iteration < time_recursion) {
        printf("\nIteration is faster by %f seconds\n", time_recursion - time_iteration);
    } else {
        printf("\nBoth methods took the same time\n");
    }
    
    return 0;
}

