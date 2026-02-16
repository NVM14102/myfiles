#include <stdio.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    int i, j, current;
    
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
}

// Function to print the array
void printArray(int arr[], int n) {
	int i;
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n,arr[n],i;
    printf("Enter Number  of values \n");
    scanf("%d", &n);
    printf("Enter %d values \n", n);
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}

