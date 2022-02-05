#include <bits/stdc++.h>
using namespace std;
int n, m, cmd, a, b, h;
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
	int left = arr[tree[node * 2]];
	int right = arr[tree[node * 2 + 1]];
	if (left <= right)
		tree[node] = tree[node * 2];
	else tree[node] = tree[node * 2 + 1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	h = (int)ceil(log2(n));
	tree.assign(1 << (h + 1), 0);
	arr.assign(1 << (h + 1), 0);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	init(1, 1, n);
	cin >> m;
	while (m--) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> a >> b;
			arr[a] = b;
			update(1, 1, n, a);
		}
		if (cmd == 2) 
			cout << tree[1] << '\n';
	}
	return 0;
}