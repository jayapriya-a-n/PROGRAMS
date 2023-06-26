#include <stdio.h>

int binary_search(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; // target not found
    }

    int mid = (low + high) / 2;
    if (arr[mid] == target) {
        return mid; // target found at index mid
    } else if (arr[mid] > target) {
        return binary_search(arr, low, mid - 1, target); // search left half
    } else {
        return binary_search(arr, mid + 1, high, target); // search right half
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    int index = binary_search(arr, 0, n - 1, target);
    if (index == -1) {
        printf("Target not found in the array\n");
    } else {
        printf("Target found at index %d\n", index);
    }
    return 0;
}
