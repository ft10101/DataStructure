
#include <stdio.h>
int binary_search(int arr[], int n, int target) {
    // Performs binary search on a sorted array to find the target value.
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    int index = binary_search(arr, n, target);

    if (index == -1) {
        printf("Target value %d not found in array.", target);
    }
    else {
        printf("Target value %d found at index %d in array.", target, index);
    }


