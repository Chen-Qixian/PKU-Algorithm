#include <bits/stdc++.h>
using namespace std;

// POJ 4101 - DFS 深搜 搜索到的位置标记为#，每发现一片新区域+1

const int maxn = 35;

int k, n;
char g[maxn][maxn];

void dfs(int i, int j, char t) {
	if(i < 0 || i >= n || j < 0 || j >= n || g[i][j] != t) return;
	g[i][j] = '#';
	dfs(i + 1, j, t);
	dfs(i - 1, j, t);
	dfs(i, j + 1, t);
	dfs(i, j - 1, t);
}

int main(void) {
	scanf("%d", &k);
	while(k -- > 0) {
		scanf("%d", &n);
		for(int i = 0 ; i < n ; i ++) {
			scanf("%s", g[i]);
		}
		int red = 0, black = 0;
		for(int i = 0 ; i < n ; i ++) {
			for(int j = 0 ; j < n ; j ++) {
				if(g[i][j] == 'r') {
					red ++;
					dfs(i, j, 'r');
				}
				else if(g[i][j] == 'b') {
					black ++;
					dfs(i, j, 'b');
				}
			}
		}
		printf("%d %d\n", red, black);
	}
	return 0;
}
