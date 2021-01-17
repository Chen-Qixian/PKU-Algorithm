#include <bits/stdc++.h>
using namespace std;

// POJ 3720

const int maxn = 110;

struct Node {
	char val;
	Node* left;
	Node* right;
};

Node node[maxn];
char s[maxn];
int offset[maxn];

void init() {
	memset(offset, 0, sizeof(offset));
	for(int i = 0 ; i < maxn ; i ++) {
		node[i].val = ' ';
		node[i].left = NULL;
		node[i].right = NULL;
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	while(n -- > 0) {
		init();
		while(~scanf("%s", s)) {
			if(s[0] == '0') break;
			int i = 0;
			while(s[i] != 0 && s[i] == '-') i ++;
			node[]
		}
	}
	return 0;
}
