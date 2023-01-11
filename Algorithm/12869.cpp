#include <bits/stdc++.h>
using namespace std;
int n, arr[4], dp[61][61][61];
int dynamic(int a, int b, int c) {
	a = max(a, 0), b = max(b, 0), c = max(c, 0);
	if (dp[a][b][c]) return dp[a][b][c];
	// a b c
	dp[a][b][c] = dynamic(a - 9, b - 3, c - 1) + 1;
	// a c b
	dp[a][b][c] = min(dp[a][b][c], dynamic(a - 9, b - 1, c - 3) + 1);
	// b a c
	dp[a][b][c] = min(dp[a][b][c], dynamic(a - 3, b - 9, c - 1) + 1);
	// b c a
	dp[a][b][c] = min(dp[a][b][c], dynamic(a - 1, b - 9, c - 3) + 1);
	// c a b
	dp[a][b][c] = min(dp[a][b][c], dynamic(a - 3, b - 1, c - 9) + 1);
	// c b a
	dp[a][b][c] = min(dp[a][b][c], dynamic(a - 1, b - 3, c - 9) + 1);
	return dp[a][b][c];
}
int main() {
	dp[0][0][0] = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cout << dynamic(arr[1], arr[2], arr[3]) - 1;
	return 0;
}