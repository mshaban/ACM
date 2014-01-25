#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k, arr[10000000], sum;

void func(int cnt)
{
    if (cnt == n)
    {
        int val = max(sum - k, 1);
        arr[val]++;
        return;
    }
    for (int i = 1; i <= m; ++i)
    {
        sum += i;
        func(cnt + 1);
        sum -= i;
    }
}

int main(int argc, char const *argv[])
{
    while (scanf("%d %d %d", &n, &m , &k), n)
    {
        memset(arr, 0, sizeof(arr));
        func(0);
        int don = 1;
        for (int i = 0; i < n; ++i) don *= m;
        double ret = 0;
        for (int i = 1; i < n * m - k + 1; ++i)
        {
            ret += i * (arr[i] * 1.0 / don * 1.0);
        }
        printf("%.8lf\n", ret);
    }
    return 0;
}