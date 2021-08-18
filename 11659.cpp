#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, tmp1, tmp2;
	int sum = 0;
	cin >> N >> M;
	int *dp = new int[N+1] {0, };
	for (int i = 1; i <= N; i++) {
		cin >> tmp1;
		dp[i] = tmp1 + dp[i - 1];
	}
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		cout << dp[tmp2] - dp[tmp1-1] << "\n";
	}
	return 0;
}