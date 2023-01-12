#include <bits/stdc++.h>
using namespace std;
int N, M, v[101], w[101], dp[10001];
typedef pair<int, int> pii;
int knapsack() {
	for (int i = 1; i <= N; i++) {
		for (int j = 10000; j >=0; j--) {
			if(j-w[i]>=0)
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= M)
			return i;
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> v[i];
	for (int i = 1; i <= N; i++) 
		cin >> w[i];
	cout << knapsack();
	return 0;
}