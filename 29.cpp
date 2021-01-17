#include <bits/stdc++.h>
using namespace std;

// POJ Yogurt Factory

struct Node {
	int c;
	int y;
} d[10010];

int n, s;

long long get() {
	long long res = 0;
	int cur = 0;
	for(int i = 0 ; i < n ; i ++) {
		cur = INT_MAX;
		for(int j = 0 ; j <= i ; j ++) {
			cur = min(cur, (i - j) * s + d[j].c);
		}
		res += cur * d[i].y;
	}
	return res;
}

int main(void) {
	while(~scanf("%d%d", &n, &s)) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d%d", &d[i].c, &d[i].y);
		}
		printf("%lld", get());
	}
	return 0;
}
