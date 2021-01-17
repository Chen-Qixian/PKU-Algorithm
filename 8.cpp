#include <bits/stdc++.h>
using namespace std;

// POJ 1784 - DP 不会！ 背下来！！！！！！


const int maxn = 300;
const int INF = 0x3f3f3f3f;

int main()
{
    int n, p[maxn], q[maxn], w[maxn][maxn], e[maxn][maxn];
    while (scanf("%d", &n), n)
    {
        for (int i=1; i<=n; i++)
            scanf("%d", &p[i]);
        for (int i=0; i<n+1; i++)
            scanf("%d", &q[i]);
        for (int i=1; i<=n+1; i++)
        {
            e[i][i - 1] = 0;
            w[i][i - 1] = q[i - 1];
        }
        for (int l=1; l<=n; l++)
            for (int i=1; i<=n-l+1; i++)
            {
                int j = i + l - 1;
                e[i][j] = INF;
                w[i][j] = w[i][j - 1] + p[j] + q[j];
                for (int r=i; r<=j; r++)
                {
                    int t=e[i][r - 1] + e[r + 1][j] + w[i][j];
                    if (t < e[i][j])
                        e[i][j] = t;
                }
            }
        printf("%d\n", e[1][n]);
    }
    return 0;
}
