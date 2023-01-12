#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, q, cmd, p, x, h;
vector<int> tree, arr;
void update(int node, int start, int end, int idx, int diff) {
	if (idx < start || end < idx) return;
	tree[node] += diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, idx, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
	}
}
int query(int node, int start, int end, int left, int right) {
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	return query(node * 2, start, (start + end) / 2, left, right) +
		query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	h = (int)ceil(log2(n));
	tree.assign(1 << (h + 1), 0);
	arr.assign(1 << (h + 1), 0);
	while (q--) {
		cin >> cmd >> p >> x;
		if (cmd == 1) {
			update(1, 1, n, p, x);
			arr[p] += x;
		}
		if (cmd == 2)
			cout << query(1, 1, n, p, x) << '\n';
	}
	return 0;
}