#include <bits/stdc++.h>
using namespace std;
int n, m, cmd, i, j, h;
vector<int> tree, arr;
int init(int node, int start, int end) {
	if (start == end)
		return tree[node] = start;
	int left = init(node * 2, start, (start + end) / 2);
	int right = init(node * 2 + 1, (start + end) / 2 + 1, end);
	if (arr[left] <= arr[right])
		return tree[node] = left;
	return tree[node] = right;
}
void update(int node, int start, int end, int idx) {
	if (idx < start || end < idx) return;
	if (start == end) {
		tree[node] = start;
		return;
	}
	update(node * 2, start, (start + end) / 2, idx);
	update(node * 2 + 1, (start + end) / 2 + 1, end, idx);
	if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])
		tree[node] = tree[node * 2];
	else tree[node] = tree[node * 2 + 1];
}
int query(int node, int start, int end, int left, int right) {
	if (right < start || end < left) return 0;
	if (start == end) return tree[node];
	if (left <= start && end <= right) {
		int L = tree[node * 2];
		int R = tree[node * 2 + 1];
		if (arr[L] <= arr[R]) return L;
		return R;
	}
	int L = query(node * 2, start, (start + end) / 2, left, right);
	int R = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	if (arr[L] <= arr[R]) return L;
	return R;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	h = (int)ceil(log2(n));
	tree.assign(1 << (h + 1), 0);
	arr.assign(1 << (h + 1), 0);
	arr[0] = 2e9;
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