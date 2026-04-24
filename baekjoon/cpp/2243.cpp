#include <bits/stdc++.h>
#include <assert.h>
#define int long long

using namespace std;

vector<int> vect;
int n, h, a, b, c, idx, taste[1'000'001], N = 1'000'000;
int query(int now, int start, int end, int left, int right) {
	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return vect[now];
	return query(now * 2, start, (start + end) / 2, left, right) +
		query(now * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void solve(int left, int right, int p) {
	if (left > right)
		return;
	int mid = (left + right) / 2;
	int cnt = query(1, 1, N, left, mid);

	if (cnt < p) {
		solve(mid + 1, right, p - cnt);
		return;
	}
	else {
		idx = mid;
		solve(left, mid - 1, p);
		return;
	}
	return;
}
void update(int now, int start, int end, int idx, int diff) {
	if (idx < start || end < idx)
		return;
	vect[now] += diff;
	if (start != end) {
		update(now * 2, start, (start + end) / 2, idx, diff);
		update(now * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
	}
	return;
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cin >> n;
		h = (int)ceil(log2(1000001));
		vect.assign(1 << (h + 1), 0);
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			if (a == 1) {
				solve(1, N, b);
				cout << idx << '\n';
				taste[idx]--;
				update(1, 1, N, idx, -1);
			}
			else {
				cin >> c;
				taste[b] += c;
				update(1, 1, N, b, c);
			}
		}
	}();
	return 0;
}