#include <bits/stdc++.h>
using namespace std;

// POJ - 并查集，用距离平方判断代替浮点数

const int maxn = 1010;

struct P {
	int x, y;
} p[maxn];

bool vis[maxn];
int n, d;
int tree[1010];

int find(int x) {
	if(x == tree[x]) return x;
	tree[x] = find(tree[x]);
	return tree[x];
}

int distance(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main(void) {
	scanf("%d%d", &n, &d);
	// 平方
	d *= d;
	for(int i = 1 ; i <= n ; i ++) {
		tree[i] = i;
		vis[i] = false;
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	char op[5];
	int a, b, ra, rb;
	while(~scanf("%s", op)) {
		if(op[0] == 'O') {
			scanf("%d", &a);
			// 注意维护访问数组，访问过的节点才能并入！！！
			vis[a] = true;
			for(int i = 1 ; i <= n ; i ++) {
				// 注意判断条件，未修好的节点不能加入！！！
				if(i == a || !vis[i]) continue;
				if(distance(p[a].x, p[a].y, p[i].x, p[i].y) <= d) {
					ra = find(a);
					rb = find(i);
					if(ra != rb) {
						tree[rb] = ra;
					}
				}
			}
		}
		else if(op[0] == 'S') {
			scanf("%d%d", &a, &b);
			ra = find(a);
			rb = find(b);
			if(ra == rb) printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}
	return 0;
}
