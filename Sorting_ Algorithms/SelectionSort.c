#include <stdio.h>

int main() {
    int n;

    // Taking input for array size
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    int arr[n]; // Correct array declaration

    printf("Enter %d elements to the array:\n", n);
	int i,j,k,temp;
    // Input elements
    for ( k = 0; k < n; k++) {
        scanf("%d", &arr[k]);
    }

    // Printing the array before sorting
    printf("Before Sorting:\n");
    for ( i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    // Selection Sorting
    for ( i = 0; i < n - 1; i++) {
        int min = i; // Assume the current element is the smallest

        for ( j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j; // Update the index of the minimum element
            }
        }

        // Swap arr[i] with the smallest element found
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    // Printing the array after sorting
    printf("After Sorting:\n");
    for ( i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    return 0;
}

