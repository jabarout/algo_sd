#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target)
{
    // linear search, return index of target
    for(int i=0;i<n;i++){
        if (arr[i]==target){
            return i;
        }
    }
    //return -1 if not found
    return -1;
}

int jump_search(int *arr, int n, int target)
{
    int jump = sqrt(n);
    int prev = 0;
    while (arr[(int)fmin(jump, n) - 1] < target) {
        prev = jump;
        jump += sqrt(n);
        if (prev >= n)
            return -1;  // Not found
    }
    for (int i = prev; i < fmin(jump, n); i++) {
        if (arr[i] == target)
            return i; 
    }
    return -1;  
}

int binary_search(int *arr, int n, int target)
{
    // binary search on sorted array, return index
    // of target, return -1 if not found
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;  

        if (arr[mid] == target)
            return mid;               

        if (arr[mid] < target)
            low = mid + 1;            
        else
            high = mid - 1;           
    }

    return -1;  
}