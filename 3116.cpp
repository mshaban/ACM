#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
char T[5005], arr[15][105];
int b[15], m, n, text, pat, cur, totsum, mask, table[5001][1 << 13];
vector<vector<int> > vec;

void kmpPreprocess()
{
    int i = 0, j = -1; b[0] = -1;
    while (i < m)
    {
        while (j >= 0 && arr[cur][i] != arr[cur][j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

void kmpSearch()
{
    int i = 0, j = 0;
    while (i < n)
    {
        while (j >= 0 && T[i] != arr[cur][j]) j = b[j];
        i++; j++;
        if (j == m)
        {
            vec[cur].push_back(i - j);
            j = b[j];
        }
    }
}

void dp(int last)
{
    if (mask == (1 << pat) - 1)
    {
        printf("%d %d\n", last);
        totsum++;
        table[cur][mask] = 1;
        return;
    }
    if (table[cur][mask] != 0)
        return;
    for (int i = 0; i < vec.size(); ++i)
        if (!(mask & 1 << i) && !(table[cur][mask | 1 << i]))
        {
            mask |= 1 << i;
            for (int j = 0; j < vec[i].size(); ++j)
                if (vec[i][j] == last)
                    dp(vec[i][j] + strlen(arr[i]));
            mask ^= 1 << i;
        }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &pat, &text);
    for (int i = 0; i < pat; ++i)
    {
        scanf("%s", arr[i]);
    }
    int LT = 0;
    for (int i = 0; i < text; ++i)
    {
        scanf("%s", T + LT);
        LT += strlen(T + LT);
    }
    n = (int) strlen(T);
    vec.resize(pat);
    for (int i = 0; i < pat; ++i)
    {
        m = (int) strlen(arr[i]);
        cur = i;
        kmpPreprocess();
        kmpSearch();
    }
    for (int i = 0; i < vec.size(); ++i)
    {
        mask  |= 1 << i;
        for (int j = 0; j < vec[i].size(); ++j)
        {
            cur = vec[i][j];
            dp(vec[i][j] + strlen(arr[i]));
        }
        mask ^= 1 << i;
    }
    printf("%d\n", totsum);
}