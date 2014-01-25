#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, t;
char s[6105];
int table[3][6105];

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s);
        n =  (int) strlen(s);
        memset(table, 0, sizeof(table));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                table[i % 2][j] = table[(i - 1) % 2][j - 1] + (s[i - 1] == s[n - j] ? 1 : 0);
                table[i % 2][j] = max(table[i % 2][j], table[(i - 1) % 2][j]);
                table[i % 2][j] = max(table[i % 2][j], table[i % 2][j - 1]);
            }
        printf("%d\n", n - table[n % 2][n]);
    }
}
