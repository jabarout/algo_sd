#include "utils.h"

void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool is_sorted_nondecreasing(int *arr, int n)
{
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return false;
    }

    return true;
}

void copy_array(int *src, int *dst, int n)
{
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

void arrays_equal(int* str, int* oth, int n) {
    for (int i = 0; i < n; i++) {
        if (str[i] != oth[i]) {
            printf("Invalid result\n");
            return;
        }
    }
    printf("Expected result\n");
}