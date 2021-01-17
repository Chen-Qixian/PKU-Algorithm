#include <bits/stdc++.h>
using namespace std;

// POJ Cleaning shifts
int n, t;

struct Node {
	int s, e;
} sh[25010];

bool cmp(Node& a, Node& b) {
	return a.s < b.s;
}

int get() {
	sort(sh, sh + n, cmp);
	int res = 1, top = 0, cur = 0, i = 0;
	while(i < n) {
		if(sh[i].s > top + 1) return -1;
		cur = top;
		while(i < n && sh[i].s <= top + 1) {
			cur = max(cur, sh[i].e);
			i ++;
		}
		if(cur >= t) return res;
		res ++;
		top = cur;
	}
	return top >= t? res: -1;

}

int main(void) {
	while(~scanf("%d%d", &n, &t)) {
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d%d", &sh[i].s, &sh[i].e);
		}
		printf("%d\n", get());
	}
	return 0;
}
