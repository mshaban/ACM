#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k, course[55], x, tmp, mincourse, cnt, student[55][55];
int main(int argc, char const *argv[])
{
    while (scanf("%d %d %d", &n, &m, &k), n, m, k)
    {
        mincourse = 100;
        cnt = 0;
        memset(course, 0, sizeof(course));
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &student[i][0]);
            for (int j = 1; j <= student[i][0]; ++j)
            {
                scanf("%d", &student[i][j]);
                course[student[i][j]]++;
            }
        }
        for (int i = 0; i < m; ++i)
            if (course[i] > k)
                course[i] = 0;
        for (int i = 0; i < n; ++i)
        {
            tmp = 0;
            x = student[i][0];
            for (int j = 1; j <= x; ++j)
                if (course[student[i][j]] != 0)
                    tmp++;
            mincourse = min(mincourse, tmp);
        }
        printf("%d\n", mincourse);
    }
}