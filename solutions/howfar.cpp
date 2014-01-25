#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
double grid[10000][10000], x, y, mapx[100005], mapy[100005];
int n;
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf %lf", &x, &y);
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            grid[i][j] = grid[j][i] = sqrt((mapx[i] - mapx[j]) * (mapx[i] - mapx[j]) + (mapy[i] - mapy[j]) * (mapy[i] - mapy[j]));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%lf ", grid[i][j]);
        printf("\n");
    }
    return 0;
}