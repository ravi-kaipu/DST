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

void selection_sort(int *arr, int msize) {
    int min_pos;
    for (int i = 0; i < msize-1; i++) {
        /* find the minimum value between from arr[i+1 .. msize]
        and swap arr[i] with mininum value index */
        min_pos = i;
        for (int j = i+1; j < msize; j++)
            if (arr[j] < arr[min_pos])
                min_pos = j;
        swap(&arr[i], &arr[min_pos]);
    }
}

int main() {
    int unsorted_array[] = {4, 3, 2, 10, 12, 1, 5, 6};
    int msize = sizeof(unsorted_array)/sizeof(unsorted_array[0]);
    printf("Array before sorting:\n");
    print_array(unsorted_array, msize);

    selection_sort(unsorted_array, msize);

    printf("Array after sorting:\n");
    print_array(unsorted_array, msize);

    return 0;
}