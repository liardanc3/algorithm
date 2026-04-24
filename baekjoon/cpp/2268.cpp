#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, cmd, i, j, h;
vector<int> tree, arr;
int Sum(int node, int start, int end, int left, int right) {
	if (left > end || start > right)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	return Sum(node * 2, start, (start + end) / 2, left, right) +
		Sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void modify(int node, int start, int end, int idx, int diff) {
	if (idx < start || end < idx)
		return;
	tree[node] += diff;
	if (start != end) {
		modify(node * 2, start, (start + end) / 2, idx, diff);
		modify(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
	}
	return;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	h = (int)ceil(log2(n));
	tree.assign(1 << (h + 1),0);
	arr.assign(1 << (h + 1),0);
	while (m--) {
		cin >> cmd >> i >> j;
		if (cmd == 0) {
			if (i > j) swap(i, j);
			cout << Sum(1, 1, n, i, j) << '\n';
		}
		if (cmd == 1) {
			modify(1, 1, n, i, j - arr[i]);
			arr[i] = j;
		}		
	}
	return 0;
}