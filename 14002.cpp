#include <bits/stdc++.h>
using namespace std;
int idx, dp[1001], inp[1001], n, mx, len;
stack<int> s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inp[i];
		
		len = 0;
		for (int j = 1; j < i; j++) {
			if (inp[j] < inp[i])
				len = max(dp[j], len);
		}
		dp[i] = len + 1;

		if (mx < dp[i]) {
			mx = dp[i];
			idx = i;
		}
	}
	cout << mx << '\n';
	for (int i = idx; i >= 1; i--) {
		if (dp[i] == mx) {
			s.push(inp[i]);
			mx--;
		}
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}