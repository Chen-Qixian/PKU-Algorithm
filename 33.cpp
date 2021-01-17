#include <bits/stdc++.h>
using namespace std;

// 注意N开大，设置为总结点数一倍，安全
#define N (410)
#define M (N*N+4*N)

// POJ 2455 - dinic 二分

typedef long long LL;

using namespace std;

// 定义一个seg结构存储边信息
struct Seg {
	int a, b, w;
} seg[M];

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

  assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
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
	int n, p, t;
	scanf("%d%d%d", &n, &p, &t);
	// 对边长度进行二分查找，输入时确定上下界
	int l = INT_MAX, h = INT_MIN;
	for(int i = 0 ; i < p ; i ++) {
		scanf("%d%d%d", &seg[i].a, &seg[i].b, &seg[i].w);
		l = min(l, seg[i].w);
		h = max(h, seg[i].w);
	}
	while(l < h) {
		int m = (l + h) / 2;
		// 每次分割都重新初始化
		dinic_init();
		for(int i = 0 ; i < p ; i ++) {
			// 注意！！！ 边界为等于号
			if(seg[i].w <= m) {
				// 注意！！！双向加边
				add_edge(seg[i].a, seg[i].b, 1, 1);
			}
		}
		LL res = dinic(1, n);
		// 根据变得数量进行二分
		if(res < t) l = m + 1;
		else h = m;
	}
	printf("%d\n", l);
	return 0;
}
