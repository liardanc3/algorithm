#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m, u, v, w, d[101], trace[101]{ 0, };
vector<pii> vect[101];
int main() {
	fill(d, d + 101, -1e9);
	d[1] = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		vect[u].push_back({ v,w });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[j] == -1e9) continue;
			for (int k = 0; k < vect[j].size(); k++) {
				ll next = vect[j][k].first;
				ll dist = vect[j][k].second;

				if ( d[next] < d[j] + dist ) {
					trace[next] = j;
					d[next] = d[j] + dist;
					if (i == n) d[next] = 1e9;
				}
			}
		}
	}
	if (d[n] == 1e9) cout << -1;
	else {
		stack<int> st;
		int now = n;
		while (now != 0) {
			st.push(now);
			now = trace[now];
		}
		while (!st.empty()) {
			cout << st.top() << ' ';
			st.pop();
		}
	}
	return 0;
}
