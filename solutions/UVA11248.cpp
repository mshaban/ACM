#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

int tc, n, m, x1, x2, p, avail[15];
double  grid [55][55], shortest [55][55], tmp, price[15];

int main(int argc, char const *argv[])
{
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d %d", &n, &m);
        memset(grid, 64, sizeof(grid));
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d", &x1, &x2);
            scanf("%lf", &tmp);
            grid[x2][x1] = grid[x1][x2] = min (tmp, grid[x1][x2]);
        }
        scanf("%d", &p);
        for (int i = 0; i < p; ++i)
            scanf("%d %lf", &avail[i], &price[i]);
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
        for (int i = 0; i < p; ++i)
        {
            
        }
    }
    return 0;
}