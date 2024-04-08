#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int main() {
	vector<pii> vect[501];
	ll N, M, A, B, C, d[501], cnt = 0;
	fill(&d[0], &d[501], 1e9);
	d[1] = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		vect[A].push_back({ B,C });
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < vect[j].size(); k++) {
				ll next = vect[j][k].first;
				ll dist = vect[j][k].second;

				if (d[next] > d[j] + dist && d[j] != 1e9) {
					d[next] = d[j] + dist;
					
					if (i == N) {
						cout << -1;
						return 0;
					}
				}
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (d[i] < 1e9)
			cout << d[i] << '\n';
		else cout << -1 << '\n';
	}
	return 0;
}