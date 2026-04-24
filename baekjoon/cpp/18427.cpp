#include <bits/stdc++.h>
using namespace std;
int N, M, H;
int lego[51][11],dp[1001],d[51][1001];
char* ctmp, * tmp;
int main() {
	cin >> N >> M >> H;
	cin.ignore();
	string stmp;
	for (int i = 1; i <= N; i++) {
		getline(cin, stmp);
		ctmp = const_cast<char*>(stmp.c_str());
		int idx = 1;
		tmp = strtok_s(ctmp, " ", &ctmp);
		while (tmp) {
			lego[i][idx++] = atoi(tmp);
			tmp = strtok_s(ctmp, " ", &ctmp);
		}
		sort(&lego[i][1], &lego[i][1 + M]);
	}
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int h = lego[i][j];
			if (h == 0) continue;
			for (int k = H; k >= h; k--) {
				d[i][k] += dp[k - h];
				d[i][k] %= 10007;
			}
		}
		for (int s = 1; s <= H; s++) {
			dp[s] += d[i][s];
			dp[s] %= 10007;
		}
	}
	cout << dp[H];
	return 0;
}