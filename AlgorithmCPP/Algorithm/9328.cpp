#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> position[27];
char arr[102][102];
string str, ans;
int t, r, c, cnt, visited[102][102], key[27];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };

void bfs() {
	queue<pii> q;
	q.push({ 0,0 });
	visited[0][0] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		[&]() {
			q.pop();

			if ('a' <= arr[y][x] && arr[y][x] <= 'z') {
				key[arr[y][x] - 'a']++;

				for (int j = 0; j < position[arr[y][x] - 'a'].size(); j++) {
					int yy = position[arr[y][x] - 'a'][j].first;
					int xx = position[arr[y][x] - 'a'][j].second;

					if (visited[yy][xx])
						continue;

					for (int k = 0; k < 4; k++) {
						int ddy = yy + dy[k];
						int ddx = xx + dx[k];

						if (visited[ddy][ddx]) {
							visited[yy][xx] = 1;
							q.push({ yy,xx });
							break;
						}
					}
				}
			}

			if (arr[y][x] == '$')
				cnt++, arr[y][x]='.';

			for (int i = 0; i < 4; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];

				if (0 <= ddy && ddy <= 101 && 0 <= ddx && ddx <= 101 && !visited[ddy][ddx] && arr[ddy][ddx] != '*') {
					if ('A' <= arr[ddy][ddx] && arr[ddy][ddx] <= 'Z') {
						if (key[arr[ddy][ddx] - 'A'])
							q.push({ ddy,ddx });
						else
							continue;
					}
					visited[ddy][ddx] = 1;
					q.push({ ddy,ddx });
				}
			}
		}();
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		[&]() {
			cnt = 0;
			for (int i = 0; i <= 'z' - 'a'; i++)
				position[i].clear();
			memset(key, 0, sizeof(key));
			memset(visited, 0, sizeof(visited));
			cin >> r >> c;
			for (int i = 0; i <= 101; i++) {
				for (int j = 0; j <= 101; j++)
					arr[i][j] = '.';
			}
			for (int i = 1; i <= r; i++) {
				cin >> str;
				for (int j = 1; j <= c; j++) {
					arr[i][j] = str[j - 1];
					if ('A' <= arr[i][j] && arr[i][j] <= 'Z')
						position[arr[i][j] - 'A'].push_back({ i,j });
				}
			}
			cin >> str;
			if (str != "0") {
				for (int i = 0; i < str.size(); i++)
					key[str[i] - 'a']++;
			}
		}();
		bfs();
		ans += to_string(cnt) + '\n';
	}
	cout << ans;
	return 0;
}