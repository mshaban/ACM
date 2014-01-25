#include <stdio.h>

using namespace std;

int t, n, table[35];

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        table[1] = 1;
        table[0] = 1;
        for (int i = 2; i <= n; ++i)
            table[i]  = table[i - 1] + 2 * table[i - 2];
        printf("%d\n", table[n]);
    }
    return 0;
}