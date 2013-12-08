#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[1005];
int table[28], n;

int main(int argc, char const *argv[])
{
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i)
        table[s[i] - 'a']++;
    int cnt = 0;
    for (int i = 0; i < 27; ++i)
        if (table[i] % 2) cnt++;
    if (!cnt || cnt % 2 == 1)
        printf("First\n");
    else
        printf("Second\n");
}