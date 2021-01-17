#include <bits/stdc++.h>
using namespace std;

// POJ 2112 - dinic + 二分

// 注意顶点数设置大一些
#define N (500)
#define M (N*N+4*N)
#define INF 0x3f3f3f3f

typedef long long LL;

using namespace std;

struct edge {
  int v, cap, next;
};
edge e[M];

int head[N], level[N], cur[N];
int num_of_edges;

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

// dinic 结束
int k, c, m, v;
int g[N][N];

bool check(int lim) {
	dinic_init();
	int s = v, t = v + 1;
	// k个机器向终点添加M的边
	for(int i = 0 ; i < k ; i ++) {
		add_edge(i, t, m, 0);
	}
	// 起点向c个牛添加1的边
	for(int i = k ; i < v ; i ++) {
		add_edge(s, i, 1, 0);
	}
	// 外圈遍历机器
	for(int i = 0 ; i < k ; i ++) {
		// 内圈遍历牛
		for(int j = k ; j < v ; j ++) {
			// 边界条件注意！取等号
			if(g[i][j] <= lim) {
				// 从头牛到机器
				add_edge(j, i, 1, 0);
			}
		}
	}
	// 检查如果最大流量为牛的数量，则减小high
	return dinic(s, t) == c;
}

int solve() {
	// Floyd预处理出最短路
	for(int l = 0; l < v ; l ++) {
		for(int i = 0 ; i < v ; i ++) {
			for(int j = 0 ; j < v ; j ++) {
				g[i][j] = min(g[i][j], g[i][l] + g[l][j]);
			}
		}
	}
	int low = 0, high = 200 * v, mid;
	// 注意二分终点，相差是1
	while(high - low > 1) {
		mid = (high + low) >> 1;
		if(check(mid)) {
			high = mid;
		}
		else {
			low = mid;
		}
	}
	return high;
}

int main(void) {
	scanf("%d%d%d", &k, &c, &m);
	v = k + c;
	for(int i = 0 ; i < v ; i ++) {
		for(int j = 0 ; j < v ; j ++) {
			scanf("%d", &g[i][j]);
			// 注意关键！INF的设置！！！
			if(g[i][j] == 0) g[i][j] = INF;
		}
	}
	int res = solve();
	printf("%d\n", res);
	return 0;
}
