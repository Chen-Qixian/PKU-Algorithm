#include <bits/stdc++.h>
using namespace std;

// POJ 3479 - 网络流

// 注意N表示图中所有节点数量！！！！非常重要！！！！ 注意修改N
#define N (410)
#define M (N*N+4*N)

typedef long long LL;

using namespace std;

struct edge {
  int v, cap, next;
};
edge e[M];

int head[N], level[N], cur[N];
int num_of_edges;

// 注意每次开始时调用
void dinic_init(void) {
  num_of_edges = 0;
  memset(head, -1, sizeof(head));
  return;
}

int add_edge(int u, int v, int c1, int c2) {
  int& i=num_of_edges;
  e[i].v = v;
  e[i].cap = c1;
  e[i].next = head[u];
  head[u] = i++;

  e[i].v = u;
  e[i].cap = c2;
  e[i].next = head[v];
  head[v] = i++;
  return i;
}

int dfs(int u, int t, int bn) {
  if (u == t) return bn;
  int left = bn;
  for (int &i=cur[u]; i>=0; i=e[i].next) {
    int v = e[i].v;
    int c = e[i].cap;
    if (c > 0 && level[u]+1 == level[v]) {
      int flow = dfs(v, t, min(left, c));
      if (flow > 0) {
        e[i].cap -= flow;
        e[i^1].cap += flow;
        cur[u] = i;
        left -= flow;
        if (!left) break;
      }
    }
  }
  if (left > 0) level[u] = 0;
  return bn - left;
}

bool bfs(int s, int t) {
  memset(level, 0, sizeof(level));
  level[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == t) return true;
    for (int i=head[u]; i>=0; i=e[i].next) {
      int v = e[i].v;
      if (!level[v] && e[i].cap > 0) {
        level[v] = level[u]+1;
        q.push(v);
      }
    }
  }
  return false;
}

LL dinic(int s, int t) {
  LL max_flow = 0;

  while (bfs(s, t)) {
    memcpy(cur, head, sizeof(head));
    max_flow += dfs(s, t, INT_MAX);
  }
  return max_flow;
}

int main(void) {
	int n, f, d, lf, ld, x;
	scanf("%d%d%d", &n, &f, &d);
	// 注意！！！此调用非常重要！！！！！
	dinic_init();

	int s = 0, t = n * 2 + f + d + 1;
	for(int i = 1 ; i <= n ; i ++) {
		add_edge(i, i + n, 1, 0);
		scanf("%d%d", &lf, &ld);
		for(int j = 0 ; j < lf ; j ++) {
			scanf("%d", &x);
			add_edge(n * 2 + x, i, 1, 0);
		}
		for(int j = 0 ; j < ld ; j ++) {
			scanf("%d", &x);
			add_edge(n + i, n * 2 + f + x, 1, 0);
		}
	}
	for(int i = 1 ; i <= f ; i ++) {
		add_edge(s, n * 2 + i, 1, 0);
	}
	for(int i = 1 ; i <= d ; i ++) {
		add_edge(n * 2 + f + i, t, 1, 0);
	}
	LL res = dinic(s, t);
	printf("%lld\n", res);
	return 0;
}
