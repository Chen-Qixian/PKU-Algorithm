#include <bits/stdc++.h>
using namespace std;

// POJ 1679 - MST 判断每次加入的边是否可以有多个Kruscal

const int maxn = 110;
int tree[maxn];
int find(int x) {
	if(x == tree[x]) return x;
	tree[x] = find(tree[x]);
	return tree[x];
}

struct E {
	int a, b, w;
	bool operator < (const E& e) const {
		return w < e.w;
	}
};

vector<E> v;
int n;

void init() {
	v.clear();
	// 一定要注意编号是从1到n的！！！！！  注意编号，否则不如全都重新初始化！！！！
	for(int i = 1 ; i <= n ; i ++) {
		tree[i] = i;
	}
}

int kruscal() {
	int len = v.size(), res = 0, i = 0, j, ra, rb, ta, tb;
	while(i < len) {
		ra = find(v[i].a);
		rb = find(v[i].b);
		if(ra != rb) {
			j = i + 1;
			// 从当前位置往后找，注意j不能超出范围，找边权相等的边，判断能否加入，若能，返回-1
			while(j < len && v[j].w == v[i].w) {
				ta = find(v[j].a);
				tb = find(v[j].b);
				if(ta != tb) return -1;
				j ++;
			}
			// 更新最小生成树长度
			tree[rb] = ra;
			res += v[i].w;
			// 注意更新i
			i = j;
		}
		// 不能加入该边，遍历下一条边
		else {
			i ++;
		}
	}
	return res;
}

int main(void) {
	int t, m;
	scanf("%d", &t);
	while(t -- > 0) {
		scanf("%d%d", &n, &m);
		init();
		for(int i = 0 ; i < m ; i ++) {
			E e;
			scanf("%d%d%d", &e.a, &e.b, &e.w);
			v.push_back(e);
		}
		sort(v.begin(), v.end());
		int res = kruscal();
		// 注意！！！！ res == 0的情况！！！！ 如用例 1 0 - 返回结果应为 0！！！！！
		if(res >= 0) {
			printf("%d\n", res);
		}
		else {
			printf("Not Unique!\n");
		}
	}
	return 0;
}
