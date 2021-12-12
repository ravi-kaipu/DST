#include <stdio.h>

void print_array(int *arr, int msize) {
    for (int i = 0; i < msize; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int left = low;
    int right = high-1;
    while (left <= right) {
        if (arr[left] > arr[right]) {
            swap(&arr[left], &arr[right]);
        }
        if (arr[left] < pivot) left++;
        if (arr[right] > pivot) right--;
    }
    swap(&arr[left], &arr[high]);
    return left;
}

void quick_sort(int *arr, int l, int r) {
    if (l < r) {
        int pivot = partition(arr, l, r);
        quick_sort(arr, l, pivot - 1);
        quick_sort(arr, pivot + 1, r);
    }
}

int main() {
    int unsorted_array[] = {4, 3, 2, 10, 12, 1, 5, 6};
    int msize = sizeof(unsorted_array)/sizeof(unsorted_array[0]);
    printf("Array before sorting:\n");
    print_array(unsorted_array, msize);

    quick_sort(unsorted_array, 0, msize-1);

    printf("Array after sorting:\n");
    print_array(unsorted_array, msize);

    return 0;
}