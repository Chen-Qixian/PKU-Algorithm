#include <bits/stdc++.h>
using namespace std;

// POJ 1789 - MST 两种型号车之间编号不同的数量为边权重，以车型号为点建图

const int maxn = 2010;
char s[maxn][10];
int g[maxn][maxn];
int n;


// MST模板
struct E {
	int a;
	int b;
	int w;
	bool operator < (const E& edge) const {
		return w < edge.w;
	}
} e;

// MST用vector 存储
vector<E> v;

// 并查集
int tree[maxn];
int find(int x) {
	if(x == tree[x]) return x;
	tree[x] = find(tree[x]);
	return tree[x];
}

int main(void) {
	while(~scanf("%d", &n)) {
		if(n == 0) break;
		for(int i = 0 ; i < n ; i ++) {
			scanf("%s", s[i]);
			tree[i] = i;
		}
		// 注意初始化
		memset(g, 0, sizeof(g));
		v.clear();
		for(int i = 0 ; i < n ; i ++) {
			for(int j = i + 1 ; j < n ; j ++) {
				for(int k = 0 ; k < 7 ; k ++) {
					if(s[i][k] != s[j][k]) {
						g[i][j] ++;
						g[j][i] ++;
					}
				}
				E ed;
				ed.a = i;
				ed.b = j;
				ed.w = g[i][j];
				v.push_back(ed);
			}
		}
		sort(v.begin(), v.end());
		int ra, rb, res;
		res = 0;
		for(const auto& i: v) {
			ra = find(i.a);
			rb = find(i.b);
			if(ra != rb) {
				res += i.w;
				tree[rb] = ra;
			}
		}
		printf("The highest possible quality is 1/%d.\n",res);
		// for(const auto& x: v) {
		// 	cout << x.a << " " << x.b << " " << x.w << endl;
		// }



	}
	return 0;
}
