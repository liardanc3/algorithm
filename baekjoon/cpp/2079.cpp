#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;
string str;
int dp[2001][2001], DP[2001];
void dynamic() {
	for (int i = 0; i < str.size(); i++)
		dp[i][i] = 1;
	for (int i = 0; i < str.size() - 1; i++) {
		if(str[i]==str[i+1])
			dp[i][i + 1] = 1;
	}
	for (int gap = 2; gap < str.size(); gap++) {
		for (int i = 0; i + gap < str.size(); i++) {
			if (dp[i + 1][i + gap - 1] == 1 && str[i] == str[i + gap])
				dp[i][i + gap] = 1;
		}
	}
	for (int right = 0; right < str.size(); right++) {
		for (int left = 0; left <= right; left++) {
			if (dp[left][right] == 1) 
				DP[right] = left>=1 ? min(DP[right], DP[left - 1] + 1) : 1;
		}
	}
	cout << DP[str.size() - 1];
}
int main() {
	FASTIO;
	cin >> str;
	fill(&dp[0][0], &dp[2000][2001], 1e9);
	fill(&DP[0], &DP[2001], 1e9);
	dynamic();
	return 0;
}