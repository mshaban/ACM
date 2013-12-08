#include <stdio.h>
#include <cstring>
using namespace std;
int n, j, ret;
char  s [35];
int main(int argc, char const *argv[])
{
    while (scanf("%d", &n), n)
    {
        j  = 0 ;
        ret  = 0;
        memset(s, 0, sizeof(s));
        while (1 << j <= n)
            s[j++] = (n & 1 << j) ? '1' : '0';
        for (int i = 0; i < j; ++i)
            if (s[j - i - 1] == '1') ret |= 1 << i;
        printf("%d\n", ret);
    }
}