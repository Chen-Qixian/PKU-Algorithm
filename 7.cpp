#include <bits/stdc++.h>
using namespace std;

// POJ 1952

// bug case
// 8
// 8 8 7 7 6 6 5 5

const int maxn = 5010;
int a[maxn];
int dp[maxn];
int d[maxn];

int n, len, cnt;

int main() {
	while(~scanf("%d", &n)) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &a[i]);
			dp[i] = 1;
			d[i] = 1;
		}
		len = 1; cnt = 0;
		for(int i = 1 ; i < n ; i ++) {
			for(int j = i - 1 ; j >= 0 ; j --) {
				if(a[j] > a[i]) {
					if(dp[j] + 1 == dp[i]) {
						d[i] += d[j];
					}
					else if(dp[j] + 1 > dp[i]) {
						d[i] = d[j];
						dp[i] = dp[j] + 1;
					}
				}
				// !!! 重要判断！！！ 去重！！！
				else if(a[j] == a[i]) {
					if(dp[i] == 1) d[i] = 0;
					break;
				}
			}
			len = max(len, dp[i]);
		}
		for(int i = 0 ; i < n ; i ++) {
			if(dp[i] == len) {
				cnt += d[i];
			}
		}
		printf("%d %d\n", len, cnt);
	}
	return 0;
}
