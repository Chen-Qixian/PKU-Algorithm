#include <bits/stdc++.h>
using namespace std;

// POJ 2299 逆序对 / 重要逆序对

long long res;

void merge(vector<int>& arr, int left, int right) {
	if(left >= right) return;
	int mid = left + (right - left) / 2;
	int i = left, j = mid + 1;

	// 先更新结果值
	while(i <= mid) {
		while(j <= right && (long long) arr[j] * 2 < (long long) arr[i]) j ++;
		res += (j - mid - 1);
		i ++;
	}

	// 再开始排序过程
	i = left, j = mid + 1;
	int k = 0;
	vector<int> tmp(right - left + 1);
	while(i <= mid && j <= right) {
		if(arr[i] < arr[j]) {
			tmp[k ++] = arr[i ++];
		}
		else {
			tmp[k ++] = arr[j ++];
		}
	}
	while(i <= mid) tmp[k ++] = arr[i ++];
	while(j <= right) tmp[k ++] = arr[j ++];
	copy(tmp.begin(), tmp.end(), arr.begin() + left);
}

void mergeSort(vector<int>& arr, int l, int r) {
	if(l >= r) return;
	int m = l + (r - l) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, r);
}

int main(void) {
	int n;
	while(~scanf("%d", &n)) {
		if(n == 0) break;
		res = 0;
		vector<int> arr(n);
		for(int i = 0 ; i < n ; i ++) {
			scanf("%d", &arr[i]);
		}
		mergeSort(arr, 0, n-1);
		// for(int i = 0 ; i < n ; i ++) {
		// 	printf("%d", arr[i]);
		// }
		printf("%lld\n", res);
	}
	return 0;
}
