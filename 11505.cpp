#include <bits/stdc++.h>
#define DIV 1'000'000'007
#define int long long
using namespace std;
int n, m, k, a, b, c, h;
vector<int> tree, arr;
int init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	return tree[node] =
		((init(node * 2, start, (start + end) / 2) % DIV) *
			(init(node * 2 + 1, (start + end) / 2 + 1, end) % DIV)) % DIV;
}
int query(int node, int start, int end, int left, int right) {
	if (right < start || end < left)
		return 1;
	if (left <= start && end <= right)
		return tree[node];
	return ((query(node * 2, start, (start + end) / 2, left, right) % DIV) *
		(query(node * 2 + 1, (start + end) / 2 + 1, end, left, right) % DIV)) % DIV;
}
int update(int node, int start, int end, int idx) {
	if (idx < start || end < idx) return tree[node];
	if (start == end && idx==start) return tree[node] = arr[start];
	return tree[node]=
		((update(node * 2, start, (start + end) / 2, idx)%DIV)*
		(update(node * 2 + 1, (start + end) / 2 + 1, end, idx)%DIV))%DIV;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	h = (int)ceil(log2(n));
	tree.assign(1 << (h + 1), 1);
	arr.assign(1 << (h + 1), 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	init(1, 1, n);
	m += k;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) {
			if (arr[b] == 0) {
				arr[b] = c;
				init(1, 1, n);
			}
			else {
				arr[b] = c;
				update(1, 1, n, b);
			}
		}
		if (a == 2)
			cout << query(1, 1, n, b, c) % DIV << '\n';
	}
	return 0;
}