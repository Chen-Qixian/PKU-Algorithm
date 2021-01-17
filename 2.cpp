#include <bits/stdc++.h>
using namespace std;

// POJ 1042 - 枚举 + 贪心

const int maxn = 30;

int n, h;
int f[maxn];
int d[maxn];
int t[maxn];

int res;
int sum[maxn];

int cur;
int tf[maxn];
int tsum[maxn];

void step(int k) {
	int maxv = -1, id = 0;
	// 贪心：找到鱼最多的位置
	for(int i = 1 ; i <= k ; i ++) {
		if(tf[i] > maxv) {
			maxv = tf[i];
			id = i;
		}
	}
	// 更新
	cur += tf[id];
	tsum[id] ++;
	tf[id] = max(0, tf[id] - d[id]);
}

void get() {
	// 枚举最后停下的位置
	for(int i = 1 ; i <= n ; i ++) {
		// 总时间-走路时间 = 钓鱼时间
		int ft = h;
		for(int j = 1 ; j < i ; j ++) {
			ft -= t[j];
		}
		// 注意设置一个f的副本，因为要修改
		memset(tsum, 0, sizeof(tsum));
		for(int j = 1 ; j <= n ; j ++) {
			tf[j] = f[j];
		}
		cur = 0;
		// 枚举每一个时间应该选择钓鱼的位置，贪心选择最大化钓鱼数量的位置
		for(int j = 0 ; j < ft ; j ++) {
			step(i);
		}
		if(cur > res) {
			res = cur;
			for(int j = 1 ; j <= n ; j ++) {
				sum[j] = tsum[j];
			}
		}
	}
	// 注意输出格式！！！
	for(int i = 1 ; i < n ; i ++) {
		printf("%d, ", sum[i] * 5);
	}
	printf("%d", sum[n] * 5);
	printf("\nNumber of fish expected: %d\n\n", res);
}

int main(void) {
	while(~scanf("%d", &n)) {
		if(n == 0) break;
		scanf("%d", &h);
		h *= 12;
		for(int i = 1 ; i <= n ; i ++) scanf("%d", &f[i]);
		for(int i = 1 ; i <= n ; i ++) scanf("%d", &d[i]);
		for(int i = 1 ; i < n ; i ++) scanf("%d", &t[i]);

		// ！！！非常重要！！！每次初始化！！！
		res = 0;
		memset(sum, 0, sizeof(sum));
		// ！！！注意处理当f全0的情况！！！！
		sum[1] = h;
		get();
	}
	return 0;
}
