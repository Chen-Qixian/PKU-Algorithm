#include <bits/stdc++.h>
using namespace std;

// POJ 1094 拓扑排序

const int maxn = 30;

int indeg[maxn];
vector<int> link[maxn];
int n, m;
int res[maxn];
char s[5];

int topSort() {
	queue<int> q;
	// 注意拷贝一份
	int ind[maxn];
	int k = 1, cnt = 0;
	for(int i = 0 ; i < maxn ; i ++) {
		ind[i] = indeg[i];
	}
	for(int i = 0 ; i < n ; i ++) {
		if(ind[i] == 0) {
			q.push(i);
		}
	}
	// 拓扑排序
	while(!q.empty()) {
		// 不能唯一确定
		if(q.size() > 1) k = -1;
		int x = q.front();
		q.pop();
		res[cnt ++] = x;
		for(const auto& l: link[x]) {
			ind[l] --;
			if(ind[l] == 0) {
				q.push(l);
			}
		}
	}
	// 若最后有环，则一定会剩余节点，返回0
	if(cnt < n) return 0;
	// 返回1，标识顺序已经确定
	return k;
}

int main(void) {
	while(~scanf("%d%d", &n, &m)) {
		if(n == 0 && m == 0) break;
		// 注意初始化条件
		memset(indeg, 0, sizeof(indeg));
		for(int i = 0 ; i < maxn ; i ++) link[i].clear();
		bool signal = false;
		int v1, v2;
		for(int i = 1 ; i <= m ; i ++) {
			scanf("%s", s);
			if(signal) continue;
			v1 = s[0] - 'A';
			v2 = s[2] - 'A';
			indeg[v2] ++;
			link[v1].push_back(v2);
			int k = topSort();
			if(k == 0) {
				printf("Inconsistency found after %d relations.\n", i);
				signal = true;
			}
			else if(k == 1) {
				printf("Sorted sequence determined after %d relations: ", i);
				for(int j = 0 ; j < n ; j ++) {
					printf("%c", res[j] + 'A');
				}
				// ！！！非常重要！！！注意句号！！
				printf(".\n");
				signal = true;
			}
		}
		if(!signal) {
			printf("Sorted sequence cannot be determined.\n");
		}
	}
	return 0;
}
