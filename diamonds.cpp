#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n, red[10005], blue[10005], purple [10005], memo[10005][4];

int dp(int cur, int un)
{
    if (cur >= n)
        return 0;
    if (memo[cur][un] != -1)
        return memo[cur][un];
    int x1 = 0, x2 = 0, x3 = 0;
    if (un != 1)
        x1 = dp(cur + 1, 1) + red[cur];
    if (un != 2)
        x2 = dp(cur + 1, 2) + blue[cur];
    if (un != 3)
        x3 = dp(cur + 1, 3) + purple[cur];
    return memo[cur][un] = max(x3, max(x1, x2));
}
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        memset(memo, -1, sizeof(memo));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d %d", &red[i], &blue[i], &purple[i]);
        }
        printf("%d\n", dp(0, 0));
    }
    return 0;
}