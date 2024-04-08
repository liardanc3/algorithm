#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect[100001];

int N, M, len, a, b, c, d, level[100001], parent[100001][18], dist[100001][18];
void dfs(int now, int depth) {
	level[now] = depth;
	for (pii next : vect[now]) {
		if (level[next.first])
			continue;

		parent[next.first][0] = now;
		dist[next.first][0] = next.second;
		dfs(next.first, depth + 1);
	}
	return;
}
pii LCA(int a, int b) {
	if (level[a] < level[b])
		swap(a, b);

	int cost = 0;
	int dif = level[a] - level[b];
	for (int i = 0; dif > 0; i++) {
		if (dif % 2) {
			cost += dist[a][i];
			a = parent[a][i];
		}
		dif >>= 1;
	}

	if (a == b)
		return { cost,a };

	for (int i = len; i >= 0; i--) {
		if (parent[a][i] != 0 && parent[a][i] != parent[b][i]) {
			cost += dist[a][i];
			cost += dist[b][i];
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	return { cost + dist[a][0] + dist[b][0],parent[a][0] };
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		len = ceil(log2(N));
		for (int i = 1; i < N; i++) {
			cin >> a >> b >> c;
			vect[a].push_back({ b,c });
			vect[b].push_back({ a,c });
		}
		dfs(1, 1);
		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= N; j++) {
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
				dist[j][i] = dist[j][i - 1] + dist[parent[j][i - 1]][i - 1];
			}
		}
	}();
	cin >> M;
	while (M--) {
		cin >> a >> b >> c;
		if (a == 1)
			cout << LCA(b, c).first << '\n';
		else {
			cin >> d;
			d--;
			pii lca = LCA(b, c);
			int left = b;
			int mid = lca.second;
			int right = c;

			int gap = abs(level[mid] - level[left]);
			if (d <= gap) {
				for (int i = 0; d > 0; i++) {
					if (d & 1)
						left = parent[left][i];
					d >>= 1;
				}
				cout << left << '\n';
			}
			else {
				gap = abs(level[left] - level[mid]) + abs(level[mid] - level[right]);
				gap -= d;
				for (int i = 0; gap > 0; i++) {
					if (gap & 1)
						right = parent[right][i];
					gap >>= 1;
				}
				cout << right << '\n';
			}
		}
	}
	return 0;
}