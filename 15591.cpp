#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, Q, p, q, r, k, v, visited[5001], arr[5001][5001];
vector<int> vect[5001];
void dfs(int start, int now, int usado) {
	arr[start][now] = min(arr[start][now],usado);
	for (int i = 0; i < vect[now].size(); i++) {
		int next = vect[now][i];
		if (visited[next]) continue;
		visited[next] = 1;
		int d_usado = arr[now][next];
		dfs(start, next, min(usado,d_usado));
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill(&arr[0][0], &arr[5000][5001], 1e9);
	cin >> N >> Q;
	for (int i = 0; i < N - 1; i++) {
		cin >> p >> q >> r;
		vect[p].push_back(q);
		vect[q].push_back(p);
		arr[p][q] = r, arr[q][p] = r;
	}
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		dfs(i, i, 1e9);
	}
	for (int i = 0; i < Q; i++) {
		cin >> k >> v;
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (i == v) continue;
			if (arr[v][i] >= k) ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}