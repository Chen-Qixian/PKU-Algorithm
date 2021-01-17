#include <bits/stdc++.h>
using namespace std;
// POJ 装箱子
int main(void) {
	int a, b, c, d, e, f;
	while(~scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f)) {
		if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) break;
		int res = f + e + d + (c + 3) / 4;
		int sum2 = d * 5;
		if(c % 4 == 3) {
			sum2 += 1;
		}
		else if(c % 4 == 2) {
			sum2 += 3;
		}
		else if(c % 4 == 1) {
			sum2 += 5;
		}
		if(sum2 < b) {
			res += (b - sum2 + 8) / 9;
		}
		int sum1 = res * 36 - (f * 36 + e * 25 + d * 16 + c * 9 + b * 4);
		if(sum1 < a) {
			res += (a - sum1 + 35) / 36;
		}
		printf("%d\n", res);
	}
	return 0;
}
