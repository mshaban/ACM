#include <stdio.h>
#include <cstring>
using namespace std;

char grid[25][25];
int w, h, vis[25][25], newx, newy, cnt, sx, sy;
int dx[4] = {1, -1, 0, 0};
int dy [4] = {0 , 0, 1, -1};

void dfs(int i, int j)
{
    vis[i][j] = 1;
    for (int k = 0; k < 4; ++k)
    {
        newx = j + dx[k];
        newy = i + dy[k];
        if (newx >= 0 && newx < w && newy >= 0 && newy < h && grid[newy][newx] == '.' && !vis[newy][newx])
        {
            cnt++;
            dfs(newy, newx);
        }
    }
}

int main(int argc, char const *argv[])
{
    while (scanf("%d %d", &w, &h), w, h)
    {
        memset(vis, 0, sizeof(vis));
        cnt = 1;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
            {
                scanf(" %c", &grid[i][j]);
                if (grid[i][j] == '@')
                    sx = j, sy = i;
            }
        dfs(sy, sx);
        printf("%d\n", cnt);
    }
    return 0;
}

