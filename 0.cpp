#include <bits/stdc++.h>
using namespace std;

// POJ 1321 - dfs

int n, k;
int vis[10];
int res, m;
char g[10][10];


// 逐层dfs 注意维护vis数组
void dfs(int level) {
	if(m == k) {
		res ++;
		return;
	}
	else if(level >= n) return;
	for(int i = 0 ; i < n ; i ++) {
		if(g[level][i] == '#' && vis[i] == 0) {
			vis[i] = 1;
			m ++;
			// 本层放置后，dfs下一层
			dfs(level + 1);
			m --;
			vis[i] = 0;
		}
	}
	// 本层不放置，dfs下一层
	dfs(level + 1);
}

int main(void) {
	while(~scanf("%d%d", &n, &k)) {
		if(n == -1 && k == -1) break;
		for(int i = 0 ; i < n ; i ++) {
			scanf("%s", g[i]);
		}
		memset(vis, 0, sizeof(vis));
		res = 0; m = 0;
		dfs(0);
		printf("%d\n", res);
	}
	return 0;
}
