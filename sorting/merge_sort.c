#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int msize) {
    for (int i = 0; i < msize; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // create temp arrays
    int L[n1], R[n2];

    //copy elements in two separate array
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    /* Copy the remaining elements of R[], if there
    are any */
     while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, int l, int r) {
    if (l < r) {
        int middle = l + (r - l)/2;
        merge_sort(arr, l, middle);
        merge_sort(arr, middle+1, r);
        merge(arr, l, middle, r);
    }
}

int main() {
    int unsorted_array[] = {4, 3, 2, 10, 12, 1, 5, 6};
    int msize = sizeof(unsorted_array)/sizeof(unsorted_array[0]);
    printf("Array before sorting:\n");
    print_array(unsorted_array, msize);

    merge_sort(unsorted_array, 0, msize-1);

    printf("Array after sorting:\n");
    print_array(unsorted_array, msize);

    return 0;
}