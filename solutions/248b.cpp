#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX_N 10000300
int arr[10000000], n, cnt;

int main(int argc, char const *argv[])
{
    for (int x1 = 2; x1 < MAX_N; x1 *= 2)
        for (int x2 = 3; x2 * x1 < MAX_N; x2 *= 3)
            for (int x3 = 5; x3 * x2 * x1 < MAX_N; x3 *= 5)
                for (int x4 = 7; x4 * x3 * x1 * x2 < MAX_N; x4 *= 7)
                    arr[cnt++] = x1 * x2 * x3 * x4;
    sort(arr, arr + cnt);
    for (int i = 0; i < cnt; ++i)
        printf("%d\n", arr[i]);
    return 0;
}