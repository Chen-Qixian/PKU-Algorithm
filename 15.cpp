#include <bits/stdc++.h>
using namespace std;

// POJ 2766 - 与 6 相同

const int maxn = 110;
int sum[maxn][maxn];
int cur[maxn];
int n, t;

int main(void) {
	while(~scanf("%d", &n)) {
		for(int i = 1 ; i <= n ; i ++) {
			for(int j = 1 ; j <= n ; j ++) {
				scanf("%d", &t);
				sum[i][j] = sum[i][j-1] + t;
			}
		}
		memset(cur, 0, sizeof(cur));
		int res = INT_MIN;
		for(int i = 1 ; i <= n ; i ++) {
			for(int j = i + 1 ; j <= n ; j ++) {
				int best = 0;
				for(int k = 1 ; k <= n ; k ++) {
					cur[k] = cur[k-1] + sum[k][j] - sum[k][i-1];
					res = max(res, cur[k] - cur[best]);
					if(cur[k] < cur[best]) {
						best = k;
					}
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
