#include <bits/stdc++.h>
#define DIV 1'000'000'000
using namespace std;

int N, dp[101][10][1<<10], ans;
int dynamic(int len, int now, int visited) {
	if (dp[len][now][visited] != -1)
		return dp[len][now][visited];

	if (len == N) {
		if (visited == (1 << 10) - 1) 
			return dp[len][now][visited] = 1;
		return dp[len][now][visited] = 0;
	}
	
	cout << now;
	dp[len][now][visited] = 0;

	if (now != 0)
		dp[len][now][visited] = (dp[len][now][visited] + dynamic(len + 1, now - 1, visited | 1 << (now - 1))) % DIV;
	if (now != 9)
		dp[len][now][visited] = (dp[len][now][visited] + dynamic(len + 1, now + 1, visited | 1 << (now + 1))) % DIV;

	return dp[len][now][visited];
}
int main() {
	fill(&dp[0][0][0], &dp[100][9][1<<10], -1);
	cin >> N;
	for (int i = 1; i <= 9; i++)
		ans = (ans + dynamic(1, i, 1 << i)) % DIV;
	cout << ans;
	return 0;
}