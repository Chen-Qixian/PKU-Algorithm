#include <bits/stdc++.h>
using namespace std;

// POJ 2711 - 简单dp 双端dp

const int maxn = 110;

int a[maxn];
int n;

int get() {
	int d1[maxn];
	int d2[maxn];
	for(int i = 0 ; i < n ; i ++) {
		d1[i] = 1;
		d2[i] = 1;
	}
	for(int i = 1 ; i < n ; i ++) {
		for(int j = 0 ; j < i ; j ++) {
			if(a[j] < a[i]) {
				d1[i] = max(d1[i], d1[j] + 1);
			}
		}
	}
	for(int i = n - 2 ; i >= 0 ; i --) {
		for(int j = n - 1 ; j > i ; j --) {
			if(a[j] < a[i]) {
				d2[i] = max(d2[i], d2[j] + 1);
			}
		}
	}
	int res = 0;
	for(int i = 0 ; i < n ; i ++) {
		res = max(res, d1[i] + d2[i] - 1);
	}
	return n - res;
}

int main(void) {
	while(~scanf("%d", &n)) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &a[i]);
		}
		int res = get();
		printf("%d\n", res);
	}
	return 0;
}
