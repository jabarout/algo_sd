#include <stdbool.h>
#include <math.h>


void naive1(int n, bool isPrime[]){
    for (int i = 0; i <= n; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                isPrime[i] = false;
                break;
            }
        }
    }
}

void naive2(int n, bool isPrime[]){
    for (int i = 0; i <= n; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                isPrime[i] = false;
                break;
            }
        }
    }
}

void Meissel(int n, bool isPrime[])
{
    for (int i = 0; i <= n; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}
