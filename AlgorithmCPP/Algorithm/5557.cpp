#include <bits/stdc++.h>
#define int long long
using namespace std;
int N, arr[101]{ 0, }, dp[101][21]{ 0, };
char op[100];
void dynamic() {
	dp[1][arr[1]] = 1;
	for (int i = 2; i <= N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] != 0) {
				int next1 = j + arr[i];
				int next2 = j - arr[i];
				if (0 <= next1 && next1 <= 20)
					dp[i][next1]+=dp[i-1][j];
				if (0 <= next2 && next2 <= 20)
					dp[i][next2]+=dp[i-1][j];
			}
		}
	}
	cout << dp[N - 1][arr[N]];
}
signed main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	dynamic();
	return 0;
}