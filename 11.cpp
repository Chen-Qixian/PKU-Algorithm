#include <bits/stdc++.h>
using namespace std;

// POJ 4121 - dp 维护buy sell

const int maxn = 100010;

int a[maxn];

int n;

int get() {
	int buy[3];
	int sell[3];
	for(int i = 0 ; i < 3 ; i ++) {
		buy[i] = INT_MIN;
		sell[i] = 0;
	}
	// 核心关键！！！
	for(int i = 0 ; i < n ; i ++) {
		for(int k = 1 ; k <= 2 ; k ++) {
			// 买入必须发生在前一次交易结束后
			buy[k] = max(buy[k], sell[k-1] - a[i]);
			// 注意sell的更新：可以当天买入当天卖出
			sell[k] = max(sell[k], buy[k] + a[i]);
		}
	}
	return sell[2];
}

int main(void) {
	int t;
	scanf("%d", &t);
	while(t -- > 0) {
		scanf("%d", &n);
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &a[i]);
		}
		int res = get();
		printf("%d\n", res);
	}
	return 0;
}
