#include <bits/stdc++.h>
using namespace std;

// POJ 1511 - dijkstra + queue

typedef long long ll;
const int maxn = 1000010;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int x[maxn], y[maxn], w[maxn];
ll dis[maxn];
int head[maxn];
bool vis[maxn];
int n, m, cnt;

struct E {
	int to;
	int w;
	int next;
} e[maxn];

void init() {
	for(int i = 1 ; i <= n ; i ++) {
		dis[i] = INF;
		head[i] = -1;
		vis[i] = false;
	}
	cnt = 0;
}

void addEdge(int u, int v, int w) {
	// cnt标识边的总数
	e[cnt].to = v;
	e[cnt].w = w;
	// 加边 - 维护head
	e[cnt].next = head[u];
	head[u] = cnt ++;
}

// 注意是结构体
struct cmp {
	bool operator() (const int a, const int b) {
		// 标识dis小的优先
		return dis[a] > dis[b];
	}
};

ll dijkstra() {
	priority_queue<int, vector<int>, cmp> q;
	q.push(1);
	dis[1] = 0;
	while(!q.empty()) {
		int p = q.top();
		q.pop();
		// 注意维护vis
		vis[p] = true;
		// 注意遍历的是边
		for(int i = head[p]; i != -1 ; i = e[i].next) {
			int to = e[i].to;
			int w = e[i].w;
			// 注意更新条件的比较！！
			if(!vis[to] && dis[to] > dis[p] + w) {
				dis[to] = dis[p] + w;
				q.push(to);
			}
		}
	}
	ll res = 0;
	for(int i = 1 ; i <= n ; i ++) {
		res += dis[i];
	}
	return res;
}

int main(void) {
	int t;
	scanf("%d", &t);
	while(t -- > 0) {
		scanf("%d%d", &n, &m);
		// 正反两次建图
		init();
		for(int i = 0 ; i < m ; i ++) {
			scanf("%d%d%d", &x[i], &y[i], &w[i]);
			addEdge(x[i], y[i], w[i]);
		}
		ll res = dijkstra();
		init();
		for(int i = 0 ; i < m ; i ++) {
			addEdge(y[i], x[i], w[i]);
		}
		res += dijkstra();
		printf("%lld\n", res);
	}
	return 0;
}
