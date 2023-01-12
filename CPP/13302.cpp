#include <bits/stdc++.h>
using namespace std;
int n, m, arr[101], tmp, dp[101][1000];
int dynamic(int day, int cp) {
	if (day > n) return 0;
	if (dp[day][cp] != 1e9) return dp[day][cp];
	if (arr[day]) return dp[day][cp] = dynamic(day + 1, cp);

	int mn = 1e9;
	
	mn = min(mn, dynamic(day + 1, cp) + 10000);
	mn = min(mn, dynamic(day + 3, cp + 1) + 25000);
	mn = min(mn, dynamic(day + 5, cp + 2) + 37000);
	
	if (cp >= 3)
		mn = min(mn, dynamic(day + 1, cp - 3));

	return dp[day][cp] = mn;
}
int main() {
	cin >> n >> m;
	fill(&dp[0][0], &dp[100][1000], 1e9);
	for (int i = 1; i <= m; i++) {
		cin >> tmp;
		arr[tmp] = 1;
	}
	cout << dynamic(1, 0);
	return 0;
}