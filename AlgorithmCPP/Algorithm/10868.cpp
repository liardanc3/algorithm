#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, h;
vector<int> tree, arr;
int init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	return tree[node] = min(
		init(node * 2, start, (start + end) / 2),
		init(node * 2 + 1, (start + end) / 2 + 1, end)
	);
}
int getMin(int node, int start, int end, int left, int right) {
	if (left > end || start > right)
		return 2e9;
	if (left <= start && end <= right)
		return tree[node];
	return min(
		getMin(node * 2, start, (start + end) / 2, left, right),
		getMin(node * 2 + 1, (start + end) / 2 + 1, end, left, right)
	);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	h = (int)ceil(log2(n));
	tree.assign(1 << (h + 1), 2e9);
	arr.assign(1 << (h + 1), 2e9);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	init(1, 1, n);
	while (m--) {
		cin >> a >> b;
		cout << getMin(1, 1, n, a, b) << '\n';
	}
	return 0;
}