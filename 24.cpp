#include <bits/stdc++.h>
using namespace std;

// POJ 3720 - 注意建树方法！！！


// 特殊节点 - 多了层次、方向两个属性
struct Node {
	char c;
	int level;
	int d; // 0 - left 1 - right
	Node* left;
	Node* right;
};

// 建树！！ 重点方法！！！
Node* create() {
	char s[110];
	// 建立根节点
	scanf("%s", s);
	Node* root = new Node;
	root->c = s[0];
	root->level = 0;
	root->d = 0;
	root->left = NULL;
	root->right = NULL;
	// 维护节点栈
	stack<Node*> st;
	st.push(root);
	while(~scanf("%s", s)) {
		if(s[0] == '0') break;
		int len = strlen(s);
		// 维护当前节点
		Node* cur = new Node;
		cur->c = s[len-1];
		cur->level = len-1;
		cur->d = 0;
		cur->left = NULL;
		cur->right = NULL;
		Node* r = st.top();
		// 找到直接父节点
		while(!st.empty() && cur->level - r->level != 1) {
			st.pop();
			r = st.top();
		}
		if(cur->c == '*') {
			r->d ++;
			continue;
		}
		// 根据方向添加
		if(r->d == 0) {
			r->left = cur;
			r->d ++;
		}
		else if(r->d == 1) {
			r->right = cur;
			r->d ++;
		}
		// 若栈顶放满弹出
		if(r->d == 2) {
			st.pop();
		}
		st.push(cur);
	}
	return root;
}

void pre(Node* root) {
	if(!root) return;
	printf("%c", root->c);
	pre(root->left);
	pre(root->right);
}

void ino(Node* root) {
	if(!root) return;
	ino(root->left);
	printf("%c", root->c);
	ino(root->right);
}

void pos(Node* root) {
	if(!root) return;
	pos(root->left);
	pos(root->right);
	printf("%c", root->c);
}

int main(void) {
	int n;
	scanf("%d", &n);
	while(n -- > 0) {
		Node* root = create();
		pre(root);
		printf("\n");
		pos(root);
		printf("\n");
		ino(root);
		printf("\n\n");
	}
	return 0;
}
