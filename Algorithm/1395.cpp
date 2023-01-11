#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vect, lazy;
int N, M, a, b, c, h;

void update_lazy(int now, int start, int end) {
	if (lazy[now] % 2) {
		vect[now] = (end - start + 1) - vect[now];
		if (start != end) {
			lazy[now * 2] += lazy[now];
			lazy[now * 2 + 1] += lazy[now];
		}
		lazy[now] = 0;
	}
}
void update(int now, int start, int end, int left, int right) {
	update_lazy(now, start, end);
	if (right < start || end < left)
		return;
	if (left <= start && end <= right) {
		vect[now] = (end - start + 1) - vect[now];
		if (start != end) {
			lazy[now * 2]++;
			lazy[now * 2 + 1]++;
		}
		return;
	}
	update(now * 2, start, (start + end) / 2, left, right);
	update(now * 2 + 1, (start + end) / 2 + 1, end, left, right);
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
		cin >> N >> M;
		h = (int)ceil(log2(N));
		vect.assign(1 << (h + 1), 0);
		lazy.assign(1 << (h + 1), 0);
	}();
	while (M--) {
		cin >> a >> b >> c;
		if (a == 0)
			update(1, 1, N, b, c);
		else
			cout << query(1, 1, N, b, c) << '\n';
	}
	return 0;
}