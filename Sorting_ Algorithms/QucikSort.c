#include <stdio.h>
// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (First element as pivot)
int partition(int arr[], int start, int end) {
    int pivot = arr[start];  // Choosing the first element as pivot
    int i = start + 1;       // Index for greater element
    int j = end;

    while (i <= j) {
        while (i <= j && arr[i] <= pivot)  // Move right if element is smaller than pivot
            i++;
        while (i <= j && arr[j] > pivot)   // Move left if element is greater than pivot
            j--;

        if (i < j)  // Swap if elements are in the wrong position
            swap(&arr[i], &arr[j]);
    }

    swap(&arr[start], &arr[j]); // Place pivot at its correct position
    return j;  // Return pivot index
}

void quicksort(int arr[], int start, int end) {       // Quicksort function
    if (start < end) {
        int pi = partition(arr, start, end);

        // Recursively sort the two halves
        quicksort(arr, start, pi - 1);
        quicksort(arr, pi + 1, end);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
	int i;
    for ( i = 0; i < size; i++)
        printf("%d\t ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int n;

    // Taking user input for array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];  // Declare array

    printf("Enter %d elements: ", n);
    int i;
    for ( i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original array\n ");
    printArray(arr, n);

    quicksort(arr, 0, n - 1);  // Sorting Function calling

    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}

