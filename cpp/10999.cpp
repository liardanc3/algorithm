#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vect, lazy;
int N, M, K, h, a, b, c, d, arr[1000001];
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
		vect[now] += (end - start + 1) * lazy[now];
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
		cin >> N >> M >> K;
		h = (int)ceil(log2(N));
		vect.assign(1 << (h + 1), 0);
		lazy.assign(1 << (h + 1), 0);
		for (int i = 1; i <= N; i++)
			cin >> arr[i];
		init(1, 1, N);
	}();
	for (int i = 0; i < M + K; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(1, 1, N, b, c, d);
		}
		else {
			cin >> b >> c;
			cout << query(1, 1, N, b, c) << '\n';
		}
	}
	return 0;
}