#include <bits/stdc++.h>
using namespace std;
int N, M, arr[31], tmp, dp[32][15010];

void dynamic(int idx, int weight) {
	if (dp[idx][weight])
		return;
	
	dp[idx][weight] = 1;

	if (idx > N)
		return;

	dynamic(idx + 1, weight + arr[idx]);
	dynamic(idx + 1, weight);
	dynamic(idx + 1, abs(weight - arr[idx]));

	return;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	dynamic(1, 0);
	cin >> M;
	while (M--) {
		cin >> tmp;
		if (tmp > 15000)
			cout << "N ";
		else if (dp[N + 1][tmp])
			cout << "Y ";
		else
			cout << "N ";
	}
	return 0;
}