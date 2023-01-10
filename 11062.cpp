#include <bits/stdc++.h>
using namespace std;
int T, card[1001], N, dp[1001][1001], sum;
int dynamic(int left, int right, bool a) {
	if (left + 1 == right) {
		if (a)
			return dp[left][right] = max(card[left], card[right]);
		else
			return dp[left][right] = min(card[left], card[right]);
	}
		
	if (dp[left][right] != -1)
		return dp[left][right];
	
	if (a) {
		int L = card[left] + dynamic(left + 1, right, !a);
		int R = dynamic(left, right - 1, !a) + card[right];
		return dp[left][right] = max(L, R);
	}
	else {
		int L = dynamic(left + 1, right, !a);
		int R = dynamic(left, right - 1, !a);
		return dp[left][right] = min(L, R);
	}	
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while (T--) {
		fill(&dp[0][0], &dp[1000][1001], -1);
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> card[i], sum += card[i];
		if (N == 1)
			cout << card[1] << '\n';
		else if (N == 2)
			cout << max(card[1], card[2]) << '\n';
		else 
			cout << dynamic(1, N, true) << '\n';
	}
	return 0;
}