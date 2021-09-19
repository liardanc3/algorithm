#include <bits/stdc++.h>
using namespace std;
#define INF 1e7
typedef pair<int, int> pii;
int TC, N, M, W, S, E, T;
int d[501][501];
vector<pii> vect[501];
void fwa() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (d[i][k] != INF && d[k][j] != INF)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> TC;
	while (TC--) {
		fill(&d[0][0], &d[500][501], INF);
		cin >> N >> M >> W;
		while (M--) {
			cin >> S >> E >> T;
			//vect[S].push_back(pii(E, T));
			//vect[E].push_back(pii(S, T));
			d[S][E] = min(d[S][E], T);
			d[E][S] = min(d[E][S], T);
		}
		while (W--) {
			cin >> S >> E >> T;
			//vect[S].push_back(pii(E, -T));
			d[S][E] = min(d[S][E], -T);
		}
		fwa();
		int possible = 0;
		for (int i = 1; i <= N; i++) {
			if (d[i][i] < 0) {
				possible = 1;
				break;
			}
		}
		if (possible) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}