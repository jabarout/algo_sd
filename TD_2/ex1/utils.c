#include "utils.h"

bool is_sorted_nondecreasing(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])  
            return false;
    }
    return true;
}

int min_int(int a, int b)
{
    if(a<=b){
        return a;
    }
    return b;
}