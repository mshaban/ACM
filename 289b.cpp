#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int n, m, d, arr[105 * 105];

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &n, &m, &d);
    int k = n * m;
    for (int i = 0; i < k; ++i)
        scanf("%d", &arr[i]);
    sort(arr, arr + k);
    int cnt = 0;
    for (int i = 0; i < k; ++i)
    {
        if ((arr[i] - arr[k / 2]) % d != 0)
        {
            cnt = -1;
            break;
        }
        cnt += abs(arr[i] - arr[k / 2]) / d;
    }
    printf("%d\n", cnt);
}