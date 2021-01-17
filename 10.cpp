#include <bits/stdc++.h>
using namespace std;

// POJ 2342 - 树形dp + 重点建树！！

const int maxn = 6010;

typedef pair<int, int> PII;

// 使用类似拓扑排序方式建树
vector<int> link[maxn];
int indeg[maxn];
int n;
int c[maxn];


// 返回{notdo, doit}
PII dfs(int root) {
	// 叶子节点直接返回
	if(link[root].size() == 0) return make_pair(0, c[root]);
	int len = link[root].size();
	vector<PII> v;
	for(int i = 0 ; i < len ; i ++) {
		PII r = dfs(link[root][i]);
		v.push_back(r);
	}
	int doit = c[root];
	int notdo = 0;
	len = v.size();
	for(int i = 0 ; i < len ; i ++) {
		doit += v[i].first; // do只能选子节点不做的
		notdo += max(v[i].first, v[i].second); // notdo则可以从子节点中选择大的
	}
	return make_pair(notdo, doit);
}

int main(void) {
	int  v, a, b;
	while(~scanf("%d%d", &n, &v)) {
		if(n == 0 && v == 0) break;
		memset(indeg, 0, sizeof(indeg));
		for(int i = 1 ; i <= n ; i ++) {
			link[i].clear();
		}
		c[1] = v;
		for(int i = 2 ; i <= n ; i ++) {
			scanf("%d", &c[i]);
		}
		// 记录每个节点入度，链表存储子节点
		for(int i = 1 ; i < n ; i ++) {
			scanf("%d%d", &a, &b);
			indeg[a] ++;
			link[b].push_back(a);
		}
		int root = 0;
		// 找根
		for(int i = 1 ; i <= n ; i ++) {
			if(indeg[i] == 0) {
				root = i;
				break;
			}
		}
		if(root) {
			PII res = dfs(root);
			printf("%d\n", max(res.first, res.second));
		}
	}
	return 0;
}
