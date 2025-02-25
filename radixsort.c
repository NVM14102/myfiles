#include <stdio.h>
#include <stdlib.h>

// Function to perform Counting Sort based on the digit represented by exp (10^i)
void countingSort(int arr[], int n, int exp) {
    int output[n];  // Output array to store sorted numbers
    int count[10] = {0};  // Count array for digits 0-9

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] to contain actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted numbers into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Main function to implement Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Do counting sort for every digit. The exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);  // Size of the array

    printf("Unsorted array: \n");
    printArray(arr, n);

    // Perform Radix Sort
    radixSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}

