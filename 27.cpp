#include <bits/stdc++.h>
using namespace std;

// POJ Power of Cyprotography

int main(void) {
	double n, p;
	while(~scanf("%lf%lf", &n, &p)) {
		printf("%.0lf\n", pow(p, 1.0 / n));
	}
	return 0;
}
