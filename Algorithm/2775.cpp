#include <bits/stdc++.h>
using namespace std;
int get(int k, int n) {
	int ans = 0;
	if (k > 0) {
		for (int i = 1; i <= n; i++) {
			ans += get(k - 1, i);
		}
	}
	else ans = n;
	return ans;
}
int main() {
	int t, k, n; cin >> t;
	while (t--) {
		cin >> k >> n;
		cout << get(k, n) << '\n';
	}
	return 0;
}