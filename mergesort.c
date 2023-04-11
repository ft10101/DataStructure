
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;

    // merge the two sorted subarrays into the original array
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copy any remaining elements from the left subarray
    while (i < left_size) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // copy any remaining elements from the right subarray
    while (j < right_size) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int size) {
    if (size <= 1) {
        return;  // base case: array of size 0 or 1 is already sorted
    }

    int mid = size / 2;
    int left[mid], right[size-mid];

    // copy the left half of the array into a new subarray
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    // copy the right half of the array into a new subarray
    for (int i = mid; i < size; i++) {
        right[i-mid] = arr[i];
    }

    // recursively sort the left and right subarrays
    merge_sort(left, mid);
    merge_sort(right, size-mid);

    // merge the sorted subarrays back into the original array
    merge(arr, left, mid, right, size-mid);
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    merge_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
