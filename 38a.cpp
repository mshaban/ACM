#include <stdio.h>
using namespace std;

int n, arr[105], a, b;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    n--;
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    scanf("%d %d", &a, &b);
    int ret = 0;
    for (int i = a - 1; i < b - 1; ++i)
        ret += arr[i];
    printf("%d\n", ret);
}