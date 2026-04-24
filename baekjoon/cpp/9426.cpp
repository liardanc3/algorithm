#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vect;
int N, K, arr[250001], t, ans, tmp;
void update(int now, int start, int end, int idx, int diff) {
	if (idx < start || end < idx)
		return;

	vect[now]+=diff;
	if (start != end) {
		update(now * 2, start, (start + end) / 2, idx, diff);
		update(now * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
	}
	return;
}
int query(int now, int start, int end, int left, int right) {
	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return vect[now];

	return query(now * 2, start, (start + end) / 2, left, right) +
		query(now * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void solve(int left, int right, int total) {
	if (left > right)
		return;
	int mid = (left + right) / 2;
	int cnt = query(1, 0, 65535, left, mid);

	if (cnt >= total) {
		tmp = mid;
		solve(left, mid - 1, total);
	}
	else
		solve(mid + 1, right, total - cnt);
	
	return;
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> K;
		vect.assign(1 << ((int)ceil(log2(65535)) + 1), 0);
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			update(1, 0, 65535, arr[i], 1);
			if (i < K)
				continue;
			solve(0, 65535, min((i + 1) / 2, (K + 1) / 2));
			ans += tmp;
			update(1, 0, 65535, arr[i - K + 1], -1);
		}
	}();
	cout << ans;
	return 0;
}