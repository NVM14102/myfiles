#include <stdio.h>

int main() {
    int arr[] = {7, 8, 3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, current;

    // Insertion Sort
    for (i = 1; i < n; i++) {
        current = arr[i];  
        j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than current
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }

    // Printing sorted array
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

