#include <bits/stdc++.h>
using namespace std;

// POJ 2818 - 找循环周期问题，字符串处理

const int maxn = 210;

int x[maxn];
int n, k;
char s1[maxn];
char s2[maxn];

int main(void) {
	while(~scanf("%d", &n)) {
		if(n == 0) break;
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &x[i]);
		}
		// y用于记录每个位置循环次数，寻找周期性规律
		int y[maxn] = {0};
		for(int i = 0 ; i < n ; i ++) {
			// 注意初始条件！！ 不能从i开始，因为判断相等时推出循环
			int m = x[i] - 1;
			while(true) {
				if(x[m] != x[i]) {
					m = x[m] - 1;
					y[i] ++;
				}
				else {
					// 注意边界条件！！！统计次数+1
					y[i] ++;
					break;
				}
			}
		}
		while(true) {
			scanf("%d", &k);
			if(k == 0) break;
			// 注意整行字符串读取
			getchar();
			gets(s1);
			// 补充空格处理
			for(int i = strlen(s1) ; i < n ; i ++) {
				s1[i] = ' ';
			}
			for(int i = 0 ; i < n ; i ++) {
				int m = i;
				// 循环次数
				for(int j = 0 ; j < k % y[i] ; j ++) {
					m = x[m] - 1;
				}
				s2[m] = s1[i];
			}
			// 字符串结尾
			s2[n] = 0;
			printf("%s\n", s2);
		}
		// 注意格式！块间空行
		printf("\n");
	}
	return 0;
}
