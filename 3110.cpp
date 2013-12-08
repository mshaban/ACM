#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int w, n, x, arr[13], tmp;

int main(int argc, char const *argv[])
{
    while (scanf("%d %d", &n, &w), n, w)
    {
        memset(arr, 0, sizeof(arr));
        int hi = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &tmp);
            x = tmp / w;
            arr[x]++;
        }
        int cnt = 0;
        for (int i = 12; i >= 0; --i)
        {
            if (arr[i])
            {
                cnt  = i;
                break;
            }
        }
        for (int i = 0; i <= cnt; ++i)
            hi = max(hi, arr[i]);
        double ret = 0.01;
        for (int i = 0; i <= cnt; ++i)
        {
            ret += 1.0 * (cnt - i) / cnt * (1.0 * arr[i] / hi);
        }
        printf("%.7lf\n", ret);
    }
    return 0;
}


