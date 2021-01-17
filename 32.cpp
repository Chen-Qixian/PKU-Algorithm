#include <bits/stdc++.h>
using namespace std;

// POJ - 1094 分步拓扑排序

const int maxn = 26;
int n, m;
int indeg[maxn];
vector<int> link[maxn];
int res[maxn];
char s[5];

int topSort() {
	queue<int> q;
	int cnt = 0;
	int k = 1;
	int ind[maxn];
	for(int i = 0 ; i < n ; i ++) {
		ind[i] = indeg[i];
		if(ind[i] == 0) q.push(i);
	}
	while(!q.empty()) {
		if(q.size() > 1) k = -1;
		int x = q.front();
		res[cnt ++] = x;
		q.pop();
		for(int i = 0 ; i < link[x].size() ; i ++) {
			ind[link[x][i]] --;
			if(ind[link[x][i]] == 0) q.push(link[x][i]);
		}
	}
	if(cnt < n) return 0;
	return k;
}

int main(void) {
	while(~scanf("%d%d", &n, &m)) {
		if(n == 0 && m == 0) break;
		memset(indeg, 0, sizeof(indeg));
		for(int i = 0 ; i < maxn ; i ++) {
			link[i].clear();
		}
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
