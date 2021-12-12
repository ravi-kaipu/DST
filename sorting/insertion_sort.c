#include <stdio.h>

void print_array(int *arr, int msize) {
    for (int i = 0; i < msize; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertion_sort(int *arr, int msize) {
    int key;
    int j;
    for (int i = 1; i < msize; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int unsorted_array[] = {4, 3, 2, 10, 12, 1, 5, 6};
    int msize = sizeof(unsorted_array)/sizeof(unsorted_array[0]);
    printf("Array before sorting:\n");
    print_array(unsorted_array, msize);

    insertion_sort(unsorted_array, msize);

    printf("Array after sorting:\n");
    print_array(unsorted_array, msize);

    return 0;
}