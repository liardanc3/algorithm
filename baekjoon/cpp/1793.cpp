#include <bits/stdc++.h>	
using namespace std;
int n;
string dp[251][3];
string _plus(string a, string b) {
	string ans = "";
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a.size() < b.size()) swap(a, b);
	int up = 0;
	for (int i = 0; i < b.size(); i++) {
		int nowb = b[i] - '0';
		int nowa = a[i] - '0';
		int next = up + nowa + nowb;
		up = 0;
		if (next > 9) {
			up = next / 10;
			next %= 10;
		}
		ans += (char)(next + '0');
	}
	for (int i = b.size(); i < a.size(); i++) {
		int now = a[i] - '0';
		int next = up + now;
		up = 0;
		if (next > 9) {
			up = next / 10;
			next %= 10;
		}
		ans += (char)(next + '0');
	}
	if (up) ans += (char)(up + '0');
	reverse(ans.begin(), ans.end());
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	dp[1][0] = "1", dp[1][1] = "0", dp[1][2] = "0";
	dp[2][0] = "1", dp[2][1] = "1", dp[2][2] = "1";
	for (int i = 3; i <= 250; i++) {
		dp[i][0] = _plus(dp[i - 1][0], _plus(dp[i - 1][1], dp[i - 1][2]));
		dp[i][1] = _plus(dp[i - 2][0], _plus(dp[i - 2][1], dp[i - 2][2]));
		dp[i][2] = _plus(dp[i - 2][0], _plus(dp[i - 2][1], dp[i - 2][2]));
	}
	while (cin >> n) {
		if (cin.eof()) break;
		if (n == 0) cout << 1 << '\n';
		else cout << _plus(dp[n][0], _plus(dp[n][1],dp[n][2])) << '\n';
	}
	return 0;
}