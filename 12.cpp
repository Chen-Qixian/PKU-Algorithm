#include <bits/stdc++.h>
using namespace std;

// POJ 2251 - 注意这题是BFS ！！！！！  BFS ！！！！

const int maxn = 35;

char g[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];
int l, r, c;
int sl, sr, sc, el, er, ec;


// 坑！！！！ 注意可以上下移动！！！！！
int go[6][3] = {
	1, 0, 0,
	-1, 0, 0,
	0, 1, 0,
	0, -1, 0,
	0, 0, 1,
	0, 0, -1
};


// BFS结构，其中记录 t 时间是一种常用的手法
struct E {
	int i, j, k, t;
};

int bfs() {
	queue<E> q;
	E now;
	now.i = sl;
	now.j = sr;
	now.k = sc;
	now.t = 0;
	q.push(now);
	while(!q.empty()) {
		now = q.front();
		q.pop();
		for(int p = 0 ; p < 6 ; p ++) {
			int ni = now.i + go[p][0];
			int nj = now.j + go[p][1];
			int nk = now.k + go[p][2];
			if(ni < 0 || ni >= l || nj < 0 || nj >= r || nk < 0 || nk >= c || vis[ni][nj][nk] || g[ni][nj][nk] == '#') continue;
			// 找到就立即返回
			if(ni == el && nj == er && nk == ec) return now.t + 1;
			E tmp;
			tmp.i = ni;
			tmp.j = nj;
			tmp.k = nk;
			tmp.t = now.t + 1;
			q.push(tmp);
			vis[ni][nj][nk] = 1;
		}
	}
	return -1;
}

int main(void) {
	while(~scanf("%d%d%d", &l, &r, &c)) {
		if(l == 0 && r == 0 && c == 0) break;
		memset(vis, 0, sizeof(vis));
		for(int i = 0 ; i < l ; i ++) {
			for(int j = 0 ; j < r ; j ++) {
				scanf("%s", g[i][j]);
				for(int k = 0 ; k < c ; k ++) {
					if(g[i][j][k] == 'S') {
						sl = i;
						sr = j;
						sc = k;

						// 注意：起点访问标记！！
						vis[i][j][k] = 1;
					}
					else if(g[i][j][k] == 'E') {
						el = i;
						er = j;
						ec = k;
					}
				}
			}
		}
		int res = bfs();
		if(res > 0) {
			printf("Escaped in %d minute(s).\n", res);
		}
		else {
			printf("Trapped!\n");
		}
	}
	return 0;
}
