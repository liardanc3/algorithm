#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vect, lazy;
int N, Q1, Q2, a, b, c, d, h, arr[1000001];
void init(int now, int start, int end) {
	if (start == end)
		vect[now] = arr[start];
	else {
		init(now * 2, start, (start + end) / 2);
		init(now * 2 + 1, (start + end) / 2 + 1, end);
		vect[now] = vect[now * 2] + vect[now * 2 + 1];
	}
}
void update_lazy(int now, int start, int end) {
	if (lazy[now]) {
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
		vect[now] += diff * (end - start + 1);
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
int query(int now, int start, int end, int left, int right) {
	update_lazy(now, start, end);
	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return vect[now];
	return query(now * 2, start, (start + end) / 2, left, right) +
		query(now * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> Q1 >> Q2;
		h = (int)ceil(log2(N));
		vect.assign(1 << (h + 1), 0);
		lazy.assign(1 << (h + 1), 0);
		for (int i = 1; i <= N; i++)
			cin >> arr[i];
		init(1, 1, N);
	}();
	for (int i = 1; i <= Q1 + Q2; i++) {
		cin >> a >> b >> c;
		if (a == 1)
			cout << query(1, 1, N, b, c) << '\n';
		else {
			cin >> d;
			update(1, 1, N, b, c, d);
		}
	}
	return 0;
}