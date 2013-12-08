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
void dfs(int r, int cur)
{
    if (cur == r)
        return;
    vis[cur] = 1;
    out [r][cur] = 'N';
    for (int i = 0; i < n; ++i)
    {
        if (v[cur][i] && vis[i] == unvis)
            dfs(r, i);
    }
}
int main(int argc, char const *argv[])
{
    freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    for (int c = 0; c < t; ++c)
    {
        scanf("%d", &n);
        v.clear();
        v.resize(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", &tmp);
                v[i].push_back(tmp);
            }
        for (int i = 0 ; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                out[i][j] = 'Y';
            vis.assign(n, unvis);
            dfs(i, 0);
        }
        printf("Case %d:\n", c + 1);
        sep = "";
        for (int i = 0 ; i < n; ++i)
        {
            if (i == 0)
                sep += "+";
            sep += "--";
            if (i == n - 1)
                sep += "+";
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