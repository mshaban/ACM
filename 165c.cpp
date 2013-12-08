#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int k, sum[1000005], n;
char s[1000005];
long long ret;


int main(int argc, char const *argv[])
{

    scanf("%d", &k);
    scanf("%s", s);
    n = strlen(s);
    sum[0] = s[0] == '1' ? 1 : 0;
    for (int i = 1; i < n; ++i)
        sum[i] = sum[i - 1] + (s[i] == '1' ? 1 : 0);
    int l, u;
    for (int i = 0 ; i < n; ++i)
    {
        if (sum[i] - k < 0) continue;
        l = lower_bound(sum , sum + i, sum[i] - k) - sum;
        u = upper_bound(sum , sum + i, sum[i] - k) - sum;
        int a = 0;
        if (sum[i] - k == 0) a = 1;
        ret += (u - l) + a;
    }
    printf("%I64d\n", ret);
}

