#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, q, x, y, a, b, h;
vector<ll> tree, arr;
ll init(ll node, ll start, ll end) {
	if (start == end)
		return tree[node] = arr[start];
	return tree[node] =
		init(node * 2, start, (start + end) / 2)
		+ init(node * 2 + 1, (start + end) / 2 + 1, end);
}
ll query(ll node, ll start, ll end, ll left, ll right) {
	if (left > end || start > right)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	ll ret = query(node * 2, start, (start + end) / 2, left, right) +
		query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return ret;
}
void update(ll node, ll start, ll end, ll idx, ll diff) {
	if (idx < start || idx > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, idx, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	h = (ll)ceil(log2(n));
	tree.assign((1 << (h + 1)), 0);
	arr.assign((1 << (h + 1)), 0);
	for (ll i = 1; i <= n; i++)
		cin >> arr[i];
	init(1, 1, n);
	while (q--) {
		cin >> x >> y >> a >> b;
		cout << query(1, 1, n, min(x,y), max(x,y)) << '\n';
		ll diff = b - arr[a];
		arr[a] += diff;
		update(1, 1, n, a, diff);
	}
	return 0;
}