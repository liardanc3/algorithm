#include <bits/stdc++.h>
#define int unsigned int
using namespace std;

vector<int> vect, lazy;
int n, arr[500001], h, m, t, a, b, c;
void init(int now, int start, int end) {
	if (start == end)
		vect[now] = arr[start];
	else {
		init(now * 2, start, (start + end) / 2);
		init(now * 2 + 1, (start + end) / 2 + 1, end);
	}
}
void update_lazy(int now, int start, int end) {
	if (lazy[now]) {
		vect[now] ^= lazy[now];
		if (start != end) {
			lazy[now * 2] ^= lazy[now];
			lazy[now * 2 + 1] ^= lazy[now];
		}
		lazy[now] = 0;
	}
}
void update(int now, int start, int end, int left, int right, int diff) {
	update_lazy(now, start, end);
	if (right < start || end < left)
		return;
	if (left <= start && end <= right) {
		vect[now] ^= diff;
		if (start != end) {
			lazy[now * 2] ^= diff;
			lazy[now * 2 + 1] ^= diff;
		}
		return;
	}
	update(now * 2, start, (start + end) / 2, left, right, diff);
	update(now * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
}
int query(int now, int start, int end, int idx) {
	update_lazy(now, start, end);
	if (idx < start || end < idx)
		return 0;
	if (start == end)
		return vect[now];
	return query(now * 2, start, (start + end) / 2, idx) +
		query(now * 2 + 1, (start + end) / 2 + 1, end, idx);
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		h = (int)ceil(log2(n));
		vect.assign(1 << (h + 1), 0);
		lazy.assign(1 << (h + 1), 0);
		init(1, 1, n);
	}();
	cin >> m;
	while (m--) {
		cin >> t;
		if (t == 1) {
			cin >> a >> b >> c;
			update(1, 1, n, a+1, b+1, c);
		}
		else {
			cin >> a;
			cout << query(1, 1, n, a + 1) << '\n';
		}
	}
	return 0;
}