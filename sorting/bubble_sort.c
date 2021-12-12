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

/* compare every adjacent elements and swap
if left value is greater than right */
void bubble_sort(int *arr, int msize) {
    for (int i = 0; i < msize-1; i++) {
        for (int j = 0; j < msize-i-1; j++) {
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

int main() {
    int unsorted_array[] = {4, 3, 2, 10, 12, 1, 5, 6};
    int msize = sizeof(unsorted_array)/sizeof(unsorted_array[0]);
    printf("Array before sorting:\n");
    print_array(unsorted_array, msize);

    bubble_sort(unsorted_array, msize);

    printf("Array after sorting:\n");
    print_array(unsorted_array, msize);

    return 0;
}