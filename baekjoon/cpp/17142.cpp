#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, arr[51][51], visited[51][51], tmp[51][51], mn = 1e9, idx[10], blank;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
vector<pii> virus;
void bfs() {
	memset(visited, 0, sizeof(visited));
	copy(&arr[0][0], &arr[50][51], &tmp[0][0]);
	queue<pii> q;
	for (int i = 0; i < M; i++) {
		q.push({ virus[idx[i]].first,virus[idx[i]].second });
		visited[virus[idx[i]].first][virus[idx[i]].second] = 1;
		tmp[virus[idx[i]].first][virus[idx[i]].second] = 9;
	}
	int t = 0, _blank = blank;
	while (!q.empty() && _blank && t < mn) {
		t++;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int ddy = y + dy[k];
				int ddx = x + dx[k];

				if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N && !visited[ddy][ddx] && (tmp[ddy][ddx] == 0 || tmp[ddy][ddx] == 2)) {
					visited[ddy][ddx] = 1;
					if (!tmp[ddy][ddx])
						_blank--;
					tmp[ddy][ddx] = 9;
					q.push({ ddy,ddx });
				}
			}
		}
	}
	if (!_blank) mn = min(mn, t);
}

void dfs(int last, int len) {
	if (len == M) {
		bfs();
		return;
	}
	for (int i = last + 1; i < virus.size(); i++) {
		idx[len] = i;
		dfs(i, len + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) virus.push_back({ i,j });
			if (!arr[i][j]) blank++;
		}
	}
	dfs(-1, 0);
	if (mn == 1e9) cout << -1;
	else cout << mn;
	return 0;
}