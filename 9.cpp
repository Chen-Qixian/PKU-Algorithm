#include <bits/stdc++.h>
using namespace std;

// POJ 1384 - 完全背包问题 + 恰好装满背包

const int maxn = 510;
const int maxw = 10010;

int p[maxn];
int w[maxn];
int dp[maxw]; // dp[j] - 当装满j时的最小价值
int e, f, t, n;

int get() {
	// 初值！注意dp[0] = 0
	for(int i = 0 ; i <= t ; i ++) {
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	for(int i = 0 ; i < n ; i ++) {
		// 完全背包问题：正序遍历！
		for(int j = w[i] ; j <= t ; j ++) {
			// 注意是恰好装满背包才能更新
			if(dp[j-w[i]] != INT_MAX)
				dp[j] = min(dp[j], dp[j-w[i]] + p[i]);
		}
	}
	// 无法恰好装满
	if(dp[t] == INT_MAX) return -1;
	return dp[t];
}

int main(void) {
	int T;
	while(~scanf("%d", &T)) {
		while(T -- > 0) {
			scanf("%d%d", &e, &f);
			t = f - e;
			scanf("%d", &n);
			for(int i = 0 ; i < n ; i ++) {
				scanf("%d%d", &p[i], &w[i]);
			}
			int res = get();
			if(res == -1) {
				printf("This is impossible.\n");
			}
			else {
				printf("The minimum amount of money in the piggy-bank is %d.\n", res);
			}
		}
	}
	return 0;
}
