#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, i, v, h;
char cmd;
string ans = "";
vector<int> tree, arr;
int init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start] > 0 ? 1 : arr[start] < 0 ? -1 : 0;
	int now = init(node * 2, start, (start + end) / 2) *
		init(node * 2 + 1, (start + end) / 2 + 1, end);
	return tree[node] = now > 0 ? 1 : now < 0 ? -1 : 0;
}
void update(int node, int start, int end, int idx, int diff) {
	if (idx < start || end < idx)
		return;
	tree[node] *= diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, idx, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
	}
	return;
}
int query(int node, int start, int end, int left, int right) {
	if (right < start || end < left)
		return 1;
	if (left <= start && end <= right)
		return tree[node];
	return query(node * 2, start, (start + end) / 2, left, right) *
		query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> n) {
		if (cin.eof()) break;
		cin >> k;
		h = (int)ceil(log2(n));
		tree.assign(1 << (h + 1), 0);
		arr.assign(1 << (h + 1), 0);
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			arr[i] = arr[i] > 0 ? 1 : arr[i] < 0 ? -1 : 0;
		}
		init(1, 1, n);
		while (k--) {
			cin >> cmd >> i >> v;
			if (cmd == 'C') {
				v = v > 0 ? 1 : v < 0 ? -1 : 0;
				if (arr[i] == 0) {
					arr[i] = v;
					init(1, 1, n);
				}
				else {
					update(1, 1, n, i, v/arr[i]);
					arr[i] = v;
				}
			}
			if (cmd == 'P') {
				int ret = query(1, 1, n, i, v);
				ans += ret > 0 ? '+' : ret < 0 ? '-' : '0';
			}
		}
		tree.clear();
		arr.clear();
		cout << ans << '\n';
		ans = "";
	}
	return 0;
}