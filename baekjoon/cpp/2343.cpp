#include <bits/stdc++.h>
using namespace std;

int N, M, arr[100001], sum, sz=2e9, mx;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		sum += arr[i];
		mx = max(mx, arr[i]);
	}
	int left = mx, right = sum;
	while (left <= right) {
		int mid = (left + right) / 2;
		int disk = 1, len = 0;
		for (int i = 1; i <= N; i++) {
			if (len + arr[i] <= mid)
				len += arr[i];
			else {
				disk++;
				len = arr[i];
			}
		}

		if (disk > M) 
			left = mid + 1;
		else {
			right = mid - 1;
			sz = min(sz, mid);
		}
	}
	cout << sz;
	return 0;
}