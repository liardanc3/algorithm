#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, a, b, c, h;
vector<int> tree, arr;
int sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}
void update(int i, int diff){
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	h = (int)ceil(log2(n));
	tree.assign(n+1, 0);
	arr.assign(n+1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b,c-arr[b]);
			arr[b] = c;
		}
		if (a == 2) 
			cout << sum(c)-sum(b-1) << '\n';
	}
	return 0;
}