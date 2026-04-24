#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect[100001];

int n, arr[100001], h, a, b, c, level[100001], dist[100001][20], parent[100001][20];
int gettop(int now) {
	int mn = now;
	for (int i = h - 1; i >= 0; i--) {
		if (dist[mn][i] <= arr[now] && parent[mn][i] != 0) {
			arr[now] -= dist[mn][i];
			mn = parent[mn][i];
		}
	}
	return mn;
}
void dfs(int now, int depth) {
	level[now] = depth;
	for (int i = 0; i < vect[now].size(); i++) {
		int next = vect[now][i].first;
		int cost = vect[now][i].second;

		if (level[next])
			continue;

		dist[next][0] = cost;
		parent[next][0] = now;
		dfs(next, depth + 1);
	}
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	level[1] = 1;
	[&]() {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		for (int i = 1; i < n; i++) {
			cin >> a >> b >> c;
			vect[a].push_back({ b,c });
			vect[b].push_back({ a,c });
		}
		dfs(1, 1);
		h = ceil(log2(n));
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= n; j++) {
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
				dist[j][i] = dist[j][i - 1] + dist[parent[j][i - 1]][i - 1];
			}
		}
	}();
	for (int i = 1; i <= n; i++)
		cout << gettop(i) << '\n';
	return 0;
}