#include <bits/stdc++.h>
using namespace std;

// POJ 3726 - BFS 注意求最优解用BFS!!!

int m, n;
char g[30][30];
int si, sj, ei, ej;

struct E {
	int x, y, t;
};

int go[4][2] = {
	1, 0,
	-1, 0,
	0, 1,
	0, -1
};

int bfs() {
	E now;
	now.x = si;
	now.y = sj;
	now.t = 0;
	queue<E> q;
	q.push(now);
	g[now.x][now.y] = '#';
	while(!q.empty()) {
		now = q.front();
		q.pop();
		for(int i = 0 ; i < 4 ; i ++) {
			int nx = now.x + go[i][0];
			int ny = now.y + go[i][1];
			int nt = now.t + 1;
			if(nx < 0 || nx >= m || ny < 0 || ny >= n || g[nx][ny] == '#') continue;
			g[nx][ny] = '#';
			if(nx == ei && ny == ej) return nt;
			E tmp;
			tmp.x = nx;
			tmp.y = ny;
			tmp.t = nt;
			q.push(tmp);
		}
	}
	return -1;
}

int main(void) {
	while(~scanf("%d%d", &m, &n)) {
		if(m == 0 && n == 0) break;
		for(int i = 0 ; i < m ; i ++) {
			scanf("%s", g[i]);
			for(int j = 0 ; j < n ; j ++) {
				if(g[i][j] == '@') {
					si = i;
					sj = j;
				}
				else if(g[i][j] == '*') {
					ei = i;
					ej = j;
				}
			}
		}
		int res = bfs();
		printf("%d\n", res);
	}
	return 0;
}
