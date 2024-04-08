#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int T, N, M, C[30][30];
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	C[1][0] = 1, C[1][1] = 1;
	for (int i = 2; i <= 29; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	cin >> T;
	while (T--) {
		cin >> N >> M;
		// mCn
		cout << C[M][N] << '\n';
	}

	return 0;
}