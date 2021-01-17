#include <bits/stdc++.h>
using namespace std;

// POJ 1050
// 关键： 压缩、前缀和

int g[510][510];
int sum[510];
int n, t;

int main(void) {
	while(~scanf("%d", &n)) {
		memset(g, 0, sizeof(g));
		for(int i = 1 ; i <= n ; i ++) {
			for(int j = 1 ; j <= n ; j ++) {
				scanf("%d", &t);
				// 计算每段前缀和
				g[i][j] = g[i][j-1] + t;
			}
		}
		// 初值！！
		int res = INT_MIN;
		sum[0] = 0;
		// 外层双循环，找前缀区间
		for(int i = 1 ; i <= n ; i ++) {
			for(int j = i ; j <= n ; j ++) {
				// 每轮重制0
				int best = 0;
				// 内层遍历高度
				for(int k = 1 ; k <= n ; k ++) {
					sum[k] = sum[k-1] + g[k][j] - g[k][i-1];
					res = max(res, sum[k] - sum[best]);
					// 更新 best ：最小的sum
					if(sum[k] < sum[best]) {
						best = k;
					}
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
