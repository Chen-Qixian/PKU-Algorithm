#include <bits/stdc++.h>
using namespace std;
// POJ radar installation
int n;
double d;

double get(double y, double d) {
	return sqrt(d * d - y * y);
}

int main(void) {
	int k = 1;
	while(~scanf("%d%lf", &n, &d)) {
		if(n == 0 && d == 0) break;
		vector<vector<double> > v(n, vector<double>(2));
		double x, y;
		bool flag = true;
		for(int i = 0 ; i < n ; i ++) {
			scanf("%lf%lf", &x, &y);
			if(y > d) {
				flag = false;
				continue;
			}
			double dis = get(y, d);
			v[i][0] = x - dis;
			v[i][1] = x + dis;
		}
		if(!flag) {
			printf("Case %d: -1\n", k ++);
			continue;
		}
		sort(v.begin(), v.end(), [](const vector<double>& a, vector<double>& b) {
			return a[0] == b[0]? a[1] > b[1]: a[0] < b[0];
		});
		int res = 1;
		double l = v[0][0], r = v[0][1];
		for(int i = 1 ; i < n ; i ++) {
			if(v[i][0] > r) {
				res ++;
				l = v[i][0];
				r = v[i][1];
			}
			else if(v[i][1] < r) {
				r = v[i][1];
			}
		}

		printf("Case %d: %d\n", k ++, res);	}
	return 0;
}
