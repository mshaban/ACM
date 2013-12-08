#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX_N 1000000000000000010

long long arr[100000], n;

int main(int argc, char const *argv[])
{
    int cnt = 0;
    for (long long x1 = 1; x1 < MAX_N; x1 *= 2)
    {
        for (long long x2 = 1; x2 * x1 < MAX_N; x2 *= 3)
        {
            for (long long x3 = 1; x3 * x2 * x1 < MAX_N; x3 *= 5)
            {
                for (long long x4 = 1; x4 * x2 * x3 * x1 < MAX_N; x4 *= 7)
                {
                    arr[cnt++] =  x1 * x2 * x3 * x4;
                }
            }
        }
    }

    // printf("%d\n", cnt);
    sort(arr, arr + cnt);
    for (int i = 0; i < 40; ++i)
        printf("%d\n", arr[i]);
    int t = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", arr[n - 1]);
    }
    return 0;
}