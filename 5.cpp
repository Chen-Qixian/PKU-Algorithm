#include <bits/stdc++.h>
using namespace std;

// POJ 1088 DFS + 记忆化

int n, m;
int g[110][110];
int go[4][2] = {
	1, 0,
	-1, 0,
	0, 1,
	0, -1
};
int mp[110][110];

int dfs(int i, int j) {
	// 记忆化
	if(mp[i][j] > 0) return mp[i][j];
	int len = 1;
	for(int k = 0 ; k < 4 ; k ++) {
		int nx = i + go[k][0];
		int ny = j + go[k][1];
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		// 对符合条件的方向dfs
		if(g[nx][ny] < g[i][j]) {
			len = max(len, dfs(nx, ny) + 1);
		}
	}
	mp[i][j] = len;
	return len;
}

int main(void) {
	while(~scanf("%d%d", &n, &m)) {
		int res = 0;
		memset(mp, 0, sizeof(mp));
		for(int i = 0 ; i < n ; i ++) {
			for(int j = 0 ; j < m ; j ++) {
				scanf("%d", &g[i][j]);
			}
		}
		// 循环遍历每一个起点
		for(int i = 0 ; i < n ; i ++) {
			for(int j = 0 ; j < m ; j ++) {
				res = max(res, dfs(i, j));
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
