#include <stdio.h>
#include <algorithm>

using namespace std;

int table[4005], val[3], res, n;


int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d", &n, &val[0], &val[1], &val[2]);

    table[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 3; ++j)
        {
            if (i == val[j])
                table[i] = max(table[i], 1);
            else if (i > val[j] && table[i - val[j]])
                table[i] = max(table[i], table[val[j]] + table[i - val[j]]);
        }
    printf("%d\n", table[n]);
    return 0;
}

