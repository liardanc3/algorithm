#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, arr[51][51], idx[11], mn=1e9, visited[51][51], tmp[51][51];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
vector<pii> virus;
void bfs() {
	memset(tmp, 0, sizeof(tmp));
	memset(visited, 0, sizeof(visited));
	copy(&arr[0][0], &arr[50][51], &tmp[0][0]);
	queue<pii> q;
	for (int i = 0; i < M; i++) {
		q.push({ virus[idx[i]].first,virus[idx[i]].second });
		visited[virus[idx[i]].first][virus[idx[i]].second] = 1;
		tmp[virus[idx[i]].first][virus[idx[i]].second] = 9;
	}
	int t = -1;
	while (!q.empty()) {
		t++;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			pii now = q.front();
			q.pop();

			int y = now.first;
			int x = now.second;

			for (int j = 0; j < 4; j++) {
				int ddy = y + dy[j];
				int ddx = x + dx[j];

				if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N && !visited[ddy][ddx] && (tmp[ddy][ddx]==0 || tmp[ddy][ddx]==2)) {
					tmp[ddy][ddx] = 9;
					visited[ddy][ddx] = 1;
					q.push({ ddy,ddx });
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
		if (tmp[i][j] == 0) return;
	}
	mn = min(mn, t);
}
void dfs(int len, int last) {
	if (len == M) {
		bfs();
		return;
	}
	for (int i = last + 1; i < virus.size(); i++) {
		idx[len] = i;
		dfs(len + 1, i);
	}
	return;
}
void init() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				virus.push_back({ i,j });
		}
	}
}
int main() {
	init();
	dfs(0, -1);
	if (mn == 1e9) cout << -1;
	else cout << mn;
	return 0;
}