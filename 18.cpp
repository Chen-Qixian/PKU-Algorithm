#include <bits/stdc++.h>
using namespace std;

// POJ 3704 - 水题

int main(void) {
	char s[110];
	char r[110];
	while(~scanf("%s", s)) {
		int n = strlen(s);
		for(int i = 0 ; i < n ; i ++) {
			r[i] = ' ';
		}
		r[n] = 0;
		stack<int> st;
		int a[110];
		int ptr = 0;
		for(int i = 0 ; i < n ; i ++) {
			if(s[i] == ')') {
				if(st.empty()) {
					a[ptr ++] = i;
				}
				else {
					st.pop();
				}
			}
			else if(s[i] == '(') {
				st.push(i);
			}
		}
		while(!st.empty()) {
			r[st.top()] = '$';
			st.pop();
		}
		for(int i = 0 ; i < ptr ; i ++) {
			r[a[i]] = '?';
		}
		printf("%s\n%s\n", s, r);
	}
	return 0;
}
