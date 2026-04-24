#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vect, lazy;
int N, M, A[100001], h, cmd, a, b, c;
void init(int now, int start, int end) {
	if (start == end) 
		vect[now] = A[start];
	else {
		init(now * 2, start, (start + end) / 2);
		init(now * 2 + 1, (start + end) / 2 + 1, end);
		vect[now] = vect[now * 2] + vect[now * 2 + 1];
	}
	return;
}
void update_lazy(int now, int start, int end) {
	if (lazy[now] != 0) {
		vect[now] += (end - start + 1) * lazy[now];
		if (start != end) {
			lazy[now * 2] += lazy[now];
			lazy[now * 2 + 1] += lazy[now];
		}
		lazy[now] = 0;
	}
	return;
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
	if (idx < start || end < idx)
		return 0;

	update_lazy(now, start, end);
	if (start == end)
		return vect[now];

	return query(now * 2, start, (start + end) / 2, idx) + 
		query(now * 2 + 1, (start + end) / 2 + 1, end, idx);
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		h = (int)ceil(log2(N));
		vect.assign(1 << (h + 1), 0);
		lazy.assign(1 << (h + 1), 0);
		for (int i = 1; i <= N; i++)
			cin >> A[i];
		init(1, 1, N);
	}();
	cin >> M;
	while (M--) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> a >> b >> c;
			update(1, 1, N, a, b, c);
		}
		else {
			cin >> a;
			cout << query(1, 1, N, a) << '\n';
		}
	}
	return 0;
}