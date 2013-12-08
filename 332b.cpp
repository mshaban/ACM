#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

long long n, val[2 * 100002], k, sum[2 * 100002];

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
        cin >> val[i];
    sum[n - 1] = val[n - 1];
    for (int i = n - 2; i >= n - k; --i)
        sum[i] = (long long) sum[i + 1] + val[i];
    for (int i = n - k - 1; i >= 0; --i)
        sum[i] = (long long )sum[i + 1] + val[i] - val[i + k];
    long long a = 0, b = k, l = 0, r = 0, bb = 0;
    for (int i = n - 2 * k + 1; i >= 0; i--)
    {
        if (l <= sum[i + k]) l = sum[i + k], b = i + k;
        if (r <= l + sum[i]) r = (long long )l + sum[i], a = i, bb = b;
    }
    cout << a + 1 << " " << bb + 1 << ednl;
}