#include <bits/stdc++.h>
using namespace std;

// POJ 1182 - 偏移量并查集

const int maxn = 50010;

int p[maxn];
int d[maxn];

int find(int x) {
	if(x == p[x]) return x;
	// 注意更新方法！！！先递归修改，缓存至t
	int t = find(p[x]);
	// 更新d[x]！！！
	d[x] += d[p[x]];
	p[x] = t;
	return p[x];
}

int n, k;

int main(void) {
	scanf("%d%d", &n, &k);
	for(int i = 1 ; i <= n ; i ++) {
		p[i] = i;
		d[i] = 0;
	}
	int t, x, y, ra, rb;
	int res = 0;
	while(k -- > 0) {
		scanf("%d%d%d", &t, &x, &y);
		if(x > n || y > n) res ++;
		else {
			ra = find(x);
			rb = find(y);
			if(t == 1) {
				// 判断过且是一类
				if(ra == rb && (d[x] - d[y]) % 3) {
					res ++;
				}
				else if(ra != rb) {
					p[ra] = rb;
					// 二者设置为一类
					d[ra] = d[y] - d[x];
				}
			}
			else if(t == 2) {
				// 前面是x-y-1
				if(ra == rb && (d[x] - d[y] - 1) % 3) {
					res ++;
				}
				else if(ra != rb) {
					p[ra] = rb;
					// 更新是y+1-x（反向）
					d[ra] = d[y] - d[x] + 1;
				}
			}
		}
	}
	printf("%d\n", res);
	return 0;
}
