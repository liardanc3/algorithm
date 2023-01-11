#include <bits/stdc++.h>
using namespace std;

double mndist[201][201], mxdist[201][201], ans[201];
int N, M, a, b, c;
int main() {
	[&]() {
		fill(&mndist[0][0], &mndist[200][201], 1e9);
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			mndist[a][b] = min(mndist[a][b], (double)c);
			mndist[b][a] = min(mndist[b][a], (double)c);
			mxdist[b][a] = max(mxdist[b][a], (double)c);
			mxdist[a][b] = max(mxdist[a][b], (double)c);
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				for (int k = 1; k <= N; k++) {
					if (i == k || j == k) continue;
					mndist[j][k] = min(mndist[j][k], mndist[j][i] + mndist[i][k]);
				}
			}
		}
	}();
	[&]() {
		for (int start = 1; start <= N; start++) {
			for (int n = 1; n <= N; n++) {
				if (mndist[start][n] != 1e9)
					ans[start] = max(ans[start], mndist[start][n]);
				for (int m = 1; m <= N; m++) {
					if (mndist[start][n] == 1e9 || mndist[start][m] == 1e9 || mxdist[n][m] == 0)
						continue;
					double gap = mndist[start][n] + mxdist[n][m] - mndist[start][m];
					ans[start] = max(ans[start], mndist[start][m] + gap / 2);
				}
			}
		}
	}();
	cout.precision(1);
	cout << fixed;
	cout << *min_element(&ans[1], &ans[N + 1]);
	return 0;
}