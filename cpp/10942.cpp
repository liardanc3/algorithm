#include <bits/stdc++.h>
using namespace std;
int N, tmp, M, S, E, arr[2001], dp[2001][2001];
void makeFD(int gap) {
	for (int i = 1; i <= N - gap; i++) {
		if (arr[i] == arr[i + gap]) {
			if (gap < 2)
				dp[i][i + gap] = 1;
			else if (dp[i + 1][i + gap - 1] == 1)
				dp[i][i + gap] = 1;
		}
		if (i == N - gap) makeFD(++gap);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	makeFD(0);
	cin >> M;
	while (M--) {
		cin >> S >> E;
		cout << dp[S][E] << '\n';
	}
	return 0;
}