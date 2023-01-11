#include <bits/stdc++.h>
using namespace std;
int _a, _b, _c, dp[21][21][21];
int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20,20,20);
	else {
		if (dp[a][b][c]) return dp[a][b][c];
		if (a < b && b < c)
			return dp[a][b][c] =
			w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return dp[a][b][c] =
			w(a - 1, b, c) + w(a - 1, b - 1, c) + 
			w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> _a >> _b >> _c) {
		if (_a == -1 && _b == -1 && _c == -1) break;
		cout << "w(" << _a << ", " << _b << ", " << _c << ") = ";
		cout << w(_a,_b,_c) << '\n';
	}
	return 0;
}