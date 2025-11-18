#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        if (min_index != i) swap_int(arr + i, arr + min_index); // Or &arr[i] et &arr[min_index]
    }
}

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++) {
        int num = arr[i];
        int j = i - 1;

        while ((j >= 0) && arr[j] > num) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = num;
    }
}

void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (arr[j] < arr[j - 1]) swap_int(arr + j, arr + j - 1);
        }
    }
}

void merge(int *arr, int *tmp, int l, int m, int r)
{
    int l_idx = l, r_idx = m + 1, tmp_idx = l;
    while (l_idx <= m && r_idx <= r) {
        if (arr[l_idx] < arr[r_idx]) {
            tmp[tmp_idx++] = arr[l_idx++];
        } else {
            tmp[tmp_idx++] = arr[r_idx++];
        }
    }

    while (l_idx <= m) {
        tmp[tmp_idx++] = arr[l_idx++];
    }

    while (r_idx <= r) {
        tmp[tmp_idx++] = arr[r_idx++];
    }

    for (int i = l; i <= r; i++) {
        arr[i] = tmp[i];
    }
}

void mergesort_rec(int *arr, int *tmp, int l, int r)
{
    if (l < r) {
        int m = (l + r) / 2;
        mergesort_rec(arr, tmp, l, m);
        mergesort_rec(arr, tmp, m + 1, r);
        merge(arr, tmp, l, m, r);
    }
}

void merge_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}

int partition(int *arr, int l, int r)
{
    int pivot = arr[r];
    int last_index = l;
    for (int i = l; i < r + 1; i++) {
        if (arr[i] <= pivot) {
            swap_int(arr + i, arr + last_index);
            last_index++;
        } 
    }

    return last_index - 1;
}

void quick_sort_rec(int *arr, int l, int r)
{
    if (l < r) {
        int idx = partition(arr, l, r);
        quick_sort_rec(arr, l, idx - 1);
        quick_sort_rec(arr, idx + 1, r);
    }
}

void quick_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}