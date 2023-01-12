#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;
vector<int> permu;
char arr[21][21];
string tmp;
int t, n, m, mn, dirt, sy, sx, visited[21][21], dist[21][21];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
int bfs(int srcy, int srcx, int dsty, int dstx) {
	memset(visited, 0, sizeof(visited));
	queue<pii> q;
	q.push({ srcy,srcx });
	visited[srcy][srcx] = 1;
	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		int sz = q.size();
		while (sz--) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];

				if (ddy == dsty && ddx == dstx)
					return cnt;

				if (1 <= ddy && ddy <= n && 1 <= ddx && ddx <= m && !visited[ddy][ddx] && arr[ddy][ddx]!='x') {
					visited[ddy][ddx] = 1;
					q.push({ ddy,ddx });
				}
			}
		}
	}
	return 1e9;
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	while (cin >> m >> n) {
		if (!n && !m)
			break;
		[&]() {
			vect.clear(), permu.clear();
			fill(&dist[0][0], &dist[20][21], 1e9);
			mn = 1e9, dirt = 0;
			for (int i = 1; i <= n; i++) {
				cin >> tmp;
				for (int j = 1; j <= m; j++) {
					arr[i][j] = tmp[j - 1];
					if (arr[i][j] == 'o')
						sy = i, sx = j;
					if (arr[i][j] == '*') {
						dirt++;
						vect.push_back({ i,j });
					}
				}
			}
			for (int i = 0; i <= dirt; i++)
				dist[i][i] = 0;
			for (int i = 0; i < vect.size(); i++) {
				dist[0][i + 1] = bfs(sy, sx, vect[i].first, vect[i].second);
				dist[i + 1][0] = dist[0][i + 1];
			}
			for (int i = 0; i < vect.size() - 1; i++) {
				for (int j = i + 1; j < vect.size(); j++) {
					dist[i + 1][j + 1] = bfs(vect[i].first, vect[i].second, vect[j].first, vect[j].second);
					dist[j + 1][i + 1] = dist[i + 1][j + 1];
				}	
			}
			for (int i = 0; i <= dirt; i++) {
				for (int j = 0; j <= dirt; j++) {
					if (i == j) continue;
					for (int k = 0; k <= dirt; k++) {
						if (i == k || j == k) continue;
						dist[k][j] = min(dist[k][j], dist[k][i] + dist[i][j]);
					}
				}
			}
			for (int i = 1; i <= dirt; i++)
				permu.push_back(i);
			do {
				int d = 0;
				d += dist[0][permu[0]];
				for (int i = 0; i < permu.size()-1; i++)
					d += dist[permu[i]][permu[i + 1]];
				mn = min(mn, d);
			} while (next_permutation(permu.begin(), permu.end()));
		}();
		mn >= 1e9 ? cout << -1 << '\n' : cout << mn << '\n';
	}
	return 0;
}