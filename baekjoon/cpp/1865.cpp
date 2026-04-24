#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
typedef pair<int, int> pii;
int TC, N, M, W, S, E, T;
int d[501];
vector<pii> vect[501];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> TC;
	while (TC--) {
		
		cin >> N >> M >> W;
	
		fill(&d[0], &d[501], INF);
		//for (int i = 1; i <= N; i++)
		//	d[i] = INF;

		while (M--) {
			cin >> S >> E >> T;
			vect[S].push_back(pii(E, T));
			vect[E].push_back(pii(S, T));
			//d[S][E] = min(d[S][E], T);
			//d[E][S] = min(d[E][S], T);
		}
		while (W--) {
			cin >> S >> E >> T;
			vect[S].push_back(pii(E, -T));
			//d[S][E] = min(d[S][E], -T);
		}
		
		d[1] = 0;
		int flag = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < vect[j].size(); k++) {
					pii v = vect[j].at(k);
					int next = v.first;
					int dist = v.second;

					if (d[next] > d[j] + dist) {
						d[next] = d[j] + dist;
						if (i == N)
							flag = 1;
					}
				}
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}