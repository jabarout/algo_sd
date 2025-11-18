#include<stdio.h>
#include <time.h>
#include "fibo.h"

int main(){
    int n=45;
    long table[n+1];
    for(int i=0;i<=n;i++){
        table[i]=-1;
    }
    clock_t start, end;
    double time_recursive, time_dynamic;
    start = clock();
    long r1 = fibo(n);
    end = clock();
    time_recursive = (double)(end - start) / CLOCKS_PER_SEC;
    start = clock();
    long r2 = fibo_dyn(n,table);
    end = clock();
    time_dynamic = (double)(end - start) / CLOCKS_PER_SEC;

    printf("fibo(45) = %d, temps : %f secondes\n", r1, time_recursive);
    printf("fibo_dyn(45) = %d, temps : %f secondes\n", r2, time_dynamic);

}