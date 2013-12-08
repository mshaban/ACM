#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

int cnt[1000005], length, ret, tmp;
char s[1000005];
stack<int> st;
int main(int argc, char const *argv[])
{
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(')
            st.push(i);
        else if (!st.empty())
            cnt[st.top()] = cnt[i] = 1, st.pop();
    }
    for (int i = 0; i < n; ++i)
    { 
        if (cnt[i])
            tmp++;
        else
            tmp = 0;
        if (length == tmp)
            ret++;
        if (length < tmp)
            length = tmp, ret = 1;
    }
    if (!length)
        ret = 1;
    printf("%d %d\n", length, ret);
}
