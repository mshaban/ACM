#include <stdio.h>
#include <algorithm>
using namespace std;

int n, arr[100005], j, i;


int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    sort(arr, arr + n);
    int res = 1000000;
    for (i = 0; i < n; ++i)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (j =  n - 1; j >= i; --j)
            if (arr[i] * 2 >= arr[j])
                break;
        res = min(res, i + n - 1 - j);
    }
    printf("%d\n", res);
}