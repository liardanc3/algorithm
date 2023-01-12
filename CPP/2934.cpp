#include <bits/stdc++.h>
#include <assert.h>
#define int long long
#define MX 100'000
using namespace std;

vector<int> vect, lazy;
int N, h, L, R;

void update_lazy(int now, int start, int end) {
	if (lazy[now] != 0) {
		vect[now] += lazy[now] * (end - start + 1);
		if (start != end) {
			lazy[now * 2] += lazy[now];
			lazy[now * 2 + 1] += lazy[now];
		}
		lazy[now] = 0;
	}
}
void update(int now, int start, int end, int left, int right, int diff) {
	update_lazy(now, start, end);
	if (right < start || end < left)
		return;
	if (left <= start && end <= right) {
		vect[now] += (end - start + 1) * diff;
		if (start != end) {
			lazy[now * 2] += diff;
			lazy[now * 2 + 1] += diff;
		}
		return;
	}
	update(now * 2, start, (start + end) / 2, left, right, diff);
	update(now * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
	vect[now] = vect[now * 2] + vect[now * 2 + 1];
}
int query(int now, int start, int end, int idx) {
	update_lazy(now, start, end);
	if (idx < start || end < idx)
		return 0;
	if (start == end && idx == start)
		return vect[now];
	return query(now * 2, start, (start + end) / 2, idx) +
		query(now * 2 + 1, (start + end) / 2 + 1, end, idx);
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		h = (int)ceil(log2(MX));
		vect.assign(1 << (h + 1), 0);
		lazy.assign(1 << (h + 1), 0);
		//assert(N < 90000);
	}();
	for (int i = 1; i <= N; i++) {
		cin >> L >> R;
		int ret1 = query(1, 1, MX, L);
		int ret2 = query(1, 1, MX, R);

		cout << ret1 + ret2 << '\n';
		if (L + 1 <= R - 1)
			update(1, 1, MX, L + 1, R - 1, 1);
		if (left)
			update(1, 1, MX, L, L, -ret1);
		if (right)
			update(1, 1, MX, R, R, -ret2);
	}
	return 0;
}