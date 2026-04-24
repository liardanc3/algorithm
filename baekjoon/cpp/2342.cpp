#include <bits/stdc++.h>
using namespace std;
int a, i, dp[100001][5][5];
queue<int> q;

int gap(int a, int b) {
	if (a == 0) return 0;
	int g = abs(a - b);
	if (g == 3) g = 1;
	if (g == 0) return 1;
	if (b == 0) return 2;
	if (g == 1) return 3;
	if (g == 2) return 4;
}
void ddr() {
	if (q.size() == 0)
		return;
	fill(&dp[0][0][0], &dp[100000][4][5], 1e9);
	dp[1][0][q.front()] = 2;
	dp[1][q.front()][0] = 2;
	i = 2; q.pop();
	while (!q.empty()) {
		int cmd = q.front();
		q.pop();
		// ø¿∏•πﬂ∑Œ π‚¿Ω
		for (int j = 0; j <= 4; j++) {
			if (j == cmd) continue;
			for (int k = 0; k <= 4; k++) {
				if (j == k) {
					for (int s = 0; s <= 4; s++) {
						if(k!=s)
							dp[i][j][cmd] = min(dp[i][j][cmd], dp[i - 1][k][s] + gap(cmd, s));
					}	
				}
				else {
					for (int s = 0; s <= 4; s++) {
						if(k!=s)
							dp[i][j][cmd] = min(dp[i][j][cmd], dp[i - 1][k][s] + gap(j, k) + gap(cmd, s));
					}
				}
				if (j == 0)	k = 5;
			}
		}
		// øﬁπﬂ∑Œ π‚¿Ω
		for (int j = 0; j <= 4; j++) {
			if (j == cmd) continue;
			for (int k = 0; k <= 4; k++) {
				if (j == k) {
					for (int s = 0; s <= 4; s++) {
						if (k != s)
							dp[i][cmd][j] = min(dp[i][cmd][j], dp[i - 1][s][k] + gap(cmd, s));
					}
				}
				else {
					for (int s = 0; s <= 4; s++) {
						if (k != s)
							dp[i][cmd][j] = min(dp[i][cmd][j], dp[i - 1][s][k] + gap(j,k) + gap(cmd, s));
					}
				}
				if (j == 0)	k = 5;
			}
		}
		i++;
	}
}
int main() {
	while (cin >> a) {
		if (a == 0) break;
		q.push(a);
	}
	ddr();
	int mn = 1e9;
	for (int j = 0; j <= 4; j++) {
		for (int k = 0; k <= 4; k++) {
			if (mn > dp[i - 1][j][k])
				mn = dp[i - 1][j][k];
		}
	}
	cout << mn;
	return 0;
}