#include <bits/stdc++.h>
using namespace std;
int arr[1025][1025]{ 0, }, dp[1025][1025]{ 0, }, n, m, tmp;
int dynamic(int x1, int y1, int x2, int y2) {
	int ans = 0;
	for (int i = x1; i <= x2; i++) {
		ans += dp[i][y2] - dp[i][y1 - 1];
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tmp;
			arr[i][j] = tmp;
			dp[i][j] = dp[i][j - 1] + arr[i][j];
		}
	}
	int x1, x2, y1, y2;
	while (m--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dynamic(x1,y1,x2,y2) << '\n';
	}
	return 0;
}