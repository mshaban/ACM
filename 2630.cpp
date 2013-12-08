#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define EPS 1e-9
typedef pair<double, double>  point ;

point line [105][2];
int t, n;
double x, y, xproj[105][2], yproj[105][2];


int funcx(int i, int j)
{
    if (min(xproj[i][0], xproj[i][1]) <= min(xproj[j][0], xproj[j][1]) + EPS && max(xproj[i][0], xproj[i][1]) + EPS >= min(xproj[j][0], xproj[j][1]))
    {
        return 1;
    }
    if (min(xproj[j][0], xproj[j][1]) <= min(xproj[i][0], xproj[i][1]) + EPS && max(xproj[j][0], xproj[j][1]) + EPS >= min(xproj[i][0], xproj[i][1]))
    {
        return 1;
    }
    return 0;
}
int funcy(int i, int j)
{
    if (min(yproj[i][0], yproj[i][1]) <= min(yproj[j][0], yproj[j][1]) + EPS && max(yproj[i][0], yproj[i][1]) + EPS >= min(yproj[j][0], yproj[j][1]))
    {
        return 1;
    }
    if (min(yproj[j][0], yproj[j][1]) <= min(yproj[i][0], yproj[i][1]) + EPS && max(yproj[j][0], yproj[j][1]) + EPS >= min(yproj[i][0], yproj[i][1]))
    {
        return 1;
    }
    return 0;
}
int isParallel(point l1s, point l1e, point l2s, point l2e)
{
    double dx1 = fabs(l1s.first - l1e.first);
    double dy1 = fabs(l1s.second - l1e.second);
    double dx2 = fabs(l2s.first - l2e.first);
    double dy2 = fabs(l2s.second - l2e.second);
    if (dy1 / dx1 - dy2 / dx2 < EPS)
        return 1;
    return 0;
}
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf %lf", &x, &y);
            line[i][0] = make_pair(x, y);
            scanf("%lf %lf", &x, &y);
            line[i][1] = make_pair(x, y);
        }
        int flagx = 1, flagy = 1;
        for (int i = 0; i < n; ++i)
        {
            xproj[i][0] = line[i][0].first;
            xproj[i][1] = line[i][1].first;
        }
        for (int i = 0; i < n; ++i)
        {
            yproj[i][0] = line[i][0].second;
            yproj[i][1] = line[i][1].second;
        }
        for (int i = 0; i < n && flagx; ++i)
        {
            for (int j = i; j < n && flagx; ++j)
            {
                if (!funcx(i, j))
                {

                    flagx = 0;
                }
            }
        }
        for (int i = 0; i < n && flagy; ++i)
        {
            for (int j = i; j < n && flagy; ++j)
            {
                if (!funcy(i, j))
                {
                    flagy = 0;
                }
            }
        }
        int parallel = 1;
        if (flagy || flagx)
            printf("Yes!\n");
        else
        {
            for (int i = 0; i < n - 1 && parallel; ++i)
            {
                if (!(isParallel(line[i][0], line[i][1], line[i + 1][0], line[i + 1][1])))
                {
                    parallel = 0;
                }
            }
            if (!parallel)
            {
                printf("No!\n");
            }
            else
            {
                int sameline = 1;
                for (int i = 0; i < n - 1 && sameline; ++i)
                {
                    if (!isParallel(line[i][0], line[i + 1][1], line[i + 1][0], line[i][1]))
                    {
                        sameline = 0;
                    }
                }
                if (sameline)
                    printf("Yes!\n");
                else
                    printf("No!\n");
            }
        }
    }
}