#include <stdio.h>
#include <algorithm>
#include <bitset>
#define INF 214700000
using namespace std;
int n, m, x1, x2, val[10005], vis[10005];
bitset <10005> tree [10005];

int dfs(int cur, int root)
{
    if (vis[cur] && root == cur)
        return -INF;
    if (vis[cur])
        return 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    	ans += dfs()
    }
void DEBUG()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%d ", (int) tree[i][j]);
        printf("\n");
    }
}
int main(int argc, char const *argv[])
{
    while (scanf("%d %d", &n, &m), n, m)
    {
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d", &x1, &x2);
            tree[x1 - 1][x2 - 1] = tree[x2 - 1][x1 - 1] = 1;
        }
        for (int i = 0; i < n; ++i)
            scanf("%d", &val[i]);

    }
}