#include <bits/stdc++.h>
#define int long long
using namespace std;
int N, K, ans;
signed main() {
	cin >> N >> K;
	int left = 1, right = 100000*100000, mid, cnt;
	while (left <= right) {
		mid = (left + right)/2;

		cnt = 0;
		for (int i = 1; i <= N; i++)
			cnt += min(N, mid / i);

		if (cnt < K)
			left = mid + 1;
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}