#include <stdio.h>
#include <algorithm>
#include <cstring>
#define INF 100000000
using namespace std;

int  table[1005][1005], n, m, x, y, cnt[1005];
char grid[1005][1005];

int dp(int i, int c)
{
    if (c > y || c < x)
        return INF;
    if (i >= n)
        return 0;
    if (table[i][c] != -1)
        return table[i][c];
    return table[i][c] = min(dp(i + 1, c + 1) + (n - cnt[i]), dp(i + 1, 1) + cnt[i]);
}
int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d", &n, &m, &x, &y);
    memset(table, -1, sizeof(table));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            scanf(" %c", &grid[i][j]);
            cnt[j] += (grid[i][j] == '#');
        }
    printf("%d\n", dp(0, grid[0][0] == '#'));
    return 0;
}