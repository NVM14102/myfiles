#include <stdio.h>
// Function to merge two halves of an array
void merge(int arr[], int low, int mid, int high) 
{
    int b[10]; // Temporary array
    int i = low, j = mid + 1, k = 0;
    // Merge elements in sorted order
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
		 {
            b[k] = arr[i];
            i++;
         }
		  else 
		 {
            b[k] = arr[j];
            j++;
         }
        k++;
    }

    // Copy remaining elements from left subarray
    while (i <= mid) 
	{
        b[k] = arr[i];
        i++;
        k++;
    }
	// Copy remaining elements from right subarray
    while (j <= high)
	 {
        b[k] = arr[j];
        j++;
        k++;
    }
    // Copy merged elements back to original array
    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = b[k];
}
// Function to perform merge sort
void mergeSort(int arr[], int left, int right)
 {
    if (left < right)
	 {
        int mid = (left + right) / 2; // Find the middle point
        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}
// Main function
int main()
{
    int a[25],i,n; 
    printf("enter n value");
    scanf("%d",&n);
    printf("enter %d elements\n",n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    mergeSort(a, 0, n - 1);
    printf("Sorted array:\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
    return 0;
}
