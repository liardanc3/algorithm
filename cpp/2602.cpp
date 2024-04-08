#include <bits/stdc++.h>
using namespace std;
string text, a, b;
int dp[2][101][22], sum = 0;
int dynamic(int y, int x, int idx) {
	if (dp[y][x][idx] >= 0) return dp[y][x][idx];
	if (idx == text.size()) return dp[y][x][idx] = 1;
	if (x >= a.size()) return dp[y][x][idx] = 0;

	dp[y][x][idx] = 0;
	if (y) {
		if (text[idx] == a[x]) 
			dp[y][x][idx] += dynamic(!y, x + 1, idx + 1);
		dp[y][x][idx] += dynamic(y, x + 1, idx);
	}
	if (!y) {
		if (text[idx] == b[x])
			dp[y][x][idx] += dynamic(!y, x + 1, idx + 1);
		dp[y][x][idx] += dynamic(y, x + 1, idx);
	}

	return dp[y][x][idx];
}
int main() {
	cin >> text >> a >> b;
	fill(&dp[0][0][0], &dp[1][100][22], -1);
	sum += dynamic(0, 0, 0);
	sum += dynamic(1, 0, 0);
	cout << sum;
	return 0;
}