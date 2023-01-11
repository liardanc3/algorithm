#include <bits/stdc++.h>
using namespace std;

string tmp;
int C, N, M, arr[10][10], dp[10][10][1 << 20];

int dynamic(int r, int c, int visited) {
	if (r == 0 && c == M)
		return 0;
	if (c == M) {
		int new_visited = 0;
		for (int bef = 0, aft = M; bef < M; bef++, aft++) {
			if (visited & (1 << bef))
				new_visited |= (1 << aft);
		}
		return dynamic(r - 1, 0, new_visited);
	}
	if (dp[r][c][visited] != -1)
		return dp[r][c][visited];

	dp[r][c][visited] = 0;

	int sum = 0;
	// ÇöÀçÀÚ¸® ¾ÉÈû
	if (arr[r][c]) {
		int target = 0;
		if (c != 0) {
			target += (visited & 1 << (c - 1));
			target += (visited & 1 << (c + M - 1));
		}
		if (c != M - 1) {
			target += (visited & 1 << (c + 1));
			target += (visited & 1 << (c + M + 1));
		}
		if (!target)
			sum = max(sum, dynamic(r, c + 1, visited | 1 << c) + 1);
		else sum = max(sum, dynamic(r, c + 1, visited));
	}
	else sum = max(sum, dynamic(r, c + 1, visited));

	return dp[r][c][visited] = sum;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> C;
	while (C--) {
		[&]() {
			memset(dp, -1, sizeof(dp));
			cin >> N >> M;
			for (int i = 0; i < N; i++) {
				cin >> tmp;
				for (int j = 0; j < M; j++) {
					if (tmp[j] == '.')
						arr[i][j] = 1;
					else
						arr[i][j] = 0;
				}
			}
		}();	
		cout << dynamic(N-1, 0, 0) << '\n';
	}
	return 0;
}