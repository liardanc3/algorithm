#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> vect[100001];
int N, k, a, b, c, level[100001], parent[100001][18], mndist[100001][18], mxdist[100001][18], len;

void dfs(int now, int depth) {
	level[now] = depth;
	for (pii next : vect[now]) {
		if (level[next.first]) 
			continue;
		parent[next.first][0] = now;
		mndist[next.first][0] = mxdist[next.first][0] = next.second;
		dfs(next.first, depth + 1);
	}
}
void LCA(int a, int b) {
	int mn = 1e9, mx = 0;

	if (level[a] < level[b])
		swap(a, b);

	int dif = level[a] - level[b];
	for (int i = 0; dif > 0; i++) {
		if (dif % 2) {
			mn = min(mn, mndist[a][i]);
			mx = max(mx, mxdist[a][i]);
			a = parent[a][i];
		}
		dif >>= 1;
	}

	if (a == b) {
		cout << mn << ' ' << mx << '\n';
		return;
	}

	for (int i = len; i >= 0; i--) {
		if (parent[a][i] != 0 && parent[a][i] != parent[b][i]) {
			mn = min(mn, min(mndist[a][i], mndist[b][i]));
			mx = max(mx, max(mxdist[a][i], mxdist[b][i]));
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	mn = min(mn, min(mndist[a][0], mndist[b][0]));
	mx = max(mx, max(mxdist[a][0], mxdist[b][0]));

	cout << mn << ' ' << mx << '\n';
	return;
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		fill(&mndist[0][0], &mndist[100000][18], 1e9);
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
				mndist[j][i] = min(mndist[j][i - 1], mndist[parent[j][i - 1]][i - 1]);
				mxdist[j][i] = max(mxdist[j][i - 1], mxdist[parent[j][i - 1]][i - 1]);
			}
		}
	}();
	cin >> k;
	while (k--) {
		cin >> a >> b;
		LCA(a, b);
	}
	return 0;
}