#include <stdio.h>
#include <time.h>
#include "prime.h"

int main(void)
{
    int n = 370; 

    bool isPrime_naive1[n+1];
    bool isPrime_naive2[n+1];
    bool isPrime_Meissel[n+1];

    clock_t naive_time = clock();
    naive1(n, isPrime_naive1);
    naive1_time = clock() - naive1_time;

    clock_t naive2_time = clock();
    naive2(n, isPrime_naive2);
    naive2_time = clock() - naive2_time;

    clock_t Meissel_time = clock();
    Meissel(n, isPrime_Meissel);
    Meissel_time = clock() - Meissel_time;

    double naive1_time_sec = ((double)naive1_time) / CLOCKS_PER_SEC;
    double naive2_time_sec = ((double)naive2_time) / CLOCKS_PER_SEC;
    double Meissel_time_sec = ((double)Meissel_time) / CLOCKS_PER_SEC;

    printf("Very naive execution time: %f seconds\n", naive1_time_sec);
    printf("Naive execution time: %f seconds\n", naive2_time_sec);
    printf("Meissel execution time: %f seconds\n", Meissel_time_sec);

    return 0;
}
