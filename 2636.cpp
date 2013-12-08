#include <stdio.h>
#include <vector>
using namespace std;
int n, r, p, c, tmp;
vector<int> vec;


int main(int argc, char const *argv[])
{
    while (scanf("%d %d", &n, &r), n, r)
    {
        vec.resize(0);
        for (int i = 0; i < n; ++i)
            vec.push_back(i + 1);
        while (r--)
        {
            scanf("%d %d", &p, &c);
            p--;
            p = n - p;
            for (int i = 0; i < c; ++i)
            {
                tmp = vec[p - c];
                vec.erase(vec.begin() + (p - c));
                vec.push_back(tmp);
            }
        }
        printf("%d\n", vec[n - 1]);
    }
    return 0;
}