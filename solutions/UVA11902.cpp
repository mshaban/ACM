#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t, n, tmp;
int unvis = -1;
vector<vector<int> > v;
char out [105][105];
string sep;
vector<int> vis;
int ison [105];
void dfs(int r, int cur)
{
    if (cur == r)
        return;
    vis[cur] = 1;
    for (int i = 0; i < n; ++i)
        if (vis[i] == unvis && v[cur][i])
            dfs(r, i);
}
void explore(int cur)
{
    if (ison[cur])
        return;
    ison[cur] = 1;
    for (int i =  0; i < n; ++i)
        if (v[cur][i])
            explore(i);
}
int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    for (int c = 1; c <= t; ++c)
    {
        scanf("%d", &n);
        v.clear();
        v.resize(n);
        memset(ison, 0, sizeof(ison));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", &tmp);
                v[i].push_back(tmp);
            }
        explore(0);
        for (int i = 0 ; i < n; ++i)
        {
            vis.assign(n, unvis);
            dfs(i, 0);
            for (int j = 0; j < n; ++j)
            {
                if (vis[j] == unvis && ison[j])
                    out[i][j] = 'Y';
                else
                    out[i][j] = 'N';
            }
        }
        printf("Case %d:\n", c);
        sep = "";
        for (int i = 0 ; i < n; ++i)
        {
            if (i == 0)
                sep = "+-";
            if (i == n - 1)
                sep += "+";
            else
                sep += "--";
        }
        cout << sep << endl;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j == 0)
                    printf("|");
                printf("%c|", out[i][j]);
            }
            printf("\n");
            cout << sep << endl;
        }
    }
    return 0;
}