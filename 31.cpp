#include <bits/stdc++.h>
using namespace std;

// POJ 1308 - 并查集解决是否形成树（无环判断）

const int maxn = 10010;

int tree[maxn];
int find(int x) {
	if(x == tree[x]) return x;
	tree[x] = find(tree[x]);
	return tree[x];
}

int p[maxn][2];
int f[maxn];

void init(int& cnt) {
	memset(p, 0, sizeof(p));
	memset(f, 0, sizeof(f));
	for(int i = 0 ; i < maxn ; i ++) {
		tree[i] = i;
	}
	cnt = 0;
}

bool judge(int n) {
	int ra, rb, cnt = 0;
	for(int i = 0 ; i < n ; i ++) {
		ra = find(p[i][0]);
		rb = find(p[i][1]);
		if(ra == rb) {
			// cout << 1 << endl;
			return false;
		}
		tree[rb] = ra;
	}
	for(int i = 0 ; i < maxn ; i ++) {
		if(f[i] && tree[i] == i) {
			cnt ++;
		}
		if(cnt > 1) {
			// cout << 2 << endl;
			return false;
		}
	}
	return true;
}

int main(void) {
	int Kase = 1, cnt = 0, a, b;
	init(cnt);
	while(~scanf("%d%d", &a, &b)) {
		if(a == -1 && b == -1) break;
		else if(a == 0 && b == 0) {
			if(judge(cnt)) {
				printf("Case %d is a tree.\n", Kase ++);
			}
			else {
				printf("Case %d is not a tree.\n", Kase ++);
			}
			init(cnt);
		}
		else {
			p[cnt][0] = a; p[cnt][1] = b;
			f[a] = 1; f[b] = 1;
			cnt ++;
		}
	}
	return 0;
}
