#include <bits/stdc++.h>
#define INF 1e9+1
using namespace std;
int n, m, cmd, i, j, h;
vector<int> tree, arr;
int init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	return tree[node] = min(
		init(node * 2, start, (start + end) / 2),
		init(node * 2 + 1, (start + end) / 2 + 1, end)
	);
}
int query(int node, int start, int end, int left, int right) {
	if (right < start || end < left) return 1e9 + 1;
	if (left <= start && end <= right) return tree[node];
	return min(query(node * 2, start, (start + end) / 2, left, right),
		query(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int update(int node, int start, int end, int idx) {
	if (idx < start || end < idx) return tree[node];
	if (start == end) return tree[node] = arr[idx];
	return tree[node] = min(
		update(node * 2, start, (start + end) / 2, idx),
		update(node * 2 + 1, (start + end) / 2 + 1, end, idx)
	);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	h = (int)ceil(log2(n));
	tree.assign(1 << (h + 1), INF);
	arr.assign(1 << (h + 1), INF);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	init(1, 1, n);
	cin >> m;
	while (m--) {
		cin >> cmd >> i >> j;
		if (cmd == 1) {
			arr[i] = j;
			update(1, 1, n, i);
		}
		if (cmd == 2)
			cout << query(1,1,n,i,j) << '\n';
	}
	return 0;
}