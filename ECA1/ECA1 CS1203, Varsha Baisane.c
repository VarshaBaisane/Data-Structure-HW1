#include <stdio.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("\n");
}

// Function to generate permutations using Heap's algorithm
void permute(int n) {
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
// counters for each element
    int c[n];
    for (int i = 0; i < n; i++) {
        c[i] = 0;
    }

    printArray(arr, n);

    int i = 0;
    while (i < n) {
        if (c[i] < i) {
            if (i % 2 == 0) {
                swap(&arr[0], &arr[i]);
            } else {
                swap(&arr[c[i]], &arr[i]);
            }
            printArray(arr, n);
            c[i]++;
            i = 0;
        } else {
            c[i] = 0;
            i++;
        }
    }
}

int main() {
    int n;
    // user input between 1 to 8
    printf("Enter an integer n (1 <= n <= 8): ");
    scanf("%d", &n);

    if (n < 1 || n > 8) {
        printf("Invalid input. n must be between 1 and 8.\n");
        return 1;
    }

    permute(n);

    return 0;
}


