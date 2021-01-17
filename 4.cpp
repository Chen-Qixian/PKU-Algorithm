#include <bits/stdc++.h>
using namespace std;

// POJ 1163 - dp 注意边界


int n;
int g[110][110];
int dp[110][110];

int get() {
	dp[0][0] = g[0][0];
	for(int i = 1 ; i < n ; i ++) {
		dp[i][0] = g[i][0] + dp[i-1][0];
		for(int j = 1 ; j < i ; j ++) {
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + g[i][j];
		}
		dp[i][i] = dp[i-1][i-1] + g[i][i];
	}
	int res = 0;
	for(int i = 0 ; i < n ; i ++) {
		res = max(res, dp[n-1][i]);
	}
	return res;
}

int main(void) {
	while(~scanf("%d", &n)) {
		for(int i = 0 ; i < n ; i ++) {
			for(int j = 0 ; j <= i ; j ++) {
				scanf("%d", &g[i][j]);
			}
		}
		int res = get();
		printf("%d\n", res);
	}
	return 0;
}
