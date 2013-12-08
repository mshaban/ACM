#include <stdio.h>
#include <iostream>
using namespace std;

long long n, e;
int main(int argc, char const *argv[])
{
    n = 1118464393;
    for (long long i = 2; i <= n; ++i)
    {
        if (n % i == 0)
        {
            e = 0;
            while (n % i == 0) n /= i, e++;
            printf("%lld^%lld ", i, e);
        }
    }
    printf("\n");
    return 0;
}