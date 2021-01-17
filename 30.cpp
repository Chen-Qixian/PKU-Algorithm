#include <bits/stdc++.h>
using namespace std;

// POJ Y2K accounting bug

int main(void) {
	int s, d;
	while(~scanf("%d%d", &s, &d)) {
		int res = -1;
		if(d > 4 * s) {
			res = 10 * s - 2 * d;
		}
		else if(2 * d > 3 * s) {
			res = 8 * s - 4 * d;
		}
		else if(3 * d > 2 * s) {
			res = 6 * s - 6 * d;
		}
		else if(4 * d > s) {
			res = 3 * s - 9 * d;
		}
		if(res >= 0) {
			printf("%d\n", res);
		}
		else {
			printf("Deficit\n");
		}
	}
	return 0;
}
