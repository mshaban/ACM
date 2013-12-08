#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;

int n, i, j, palin[2005][2005];
long long   end[2005], x1, x2;
char s[2005];

int isPalindrome(int st, int end)
{
    for ( int k = 0; k <= end - st; ++k)
    {
        if (s[st + k] != s[end - k])
            return 0;
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    scanf("%s", s);
    n = strlen(s);
    start[0] = 1;

    end[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i)
    {
        end[i] = end[i + 1];
        for (int j = n - 1 ; j >= i; --j)
        {
            palin[i][j] = palin[j][i] = isPalindrome(i, j);
            end[i] += (long long )palin[i][j];
        }
    }
    long long res = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (palin[i][j])
                res += (long long) end[i + 1];
        }
    }
    cout << res;
}