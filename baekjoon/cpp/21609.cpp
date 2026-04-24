#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;

int N, M, arr[22][21], visited[21][21], rainbow, cnt, start, _cnt, _rainbow, point, cp[22][21];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 }, vvisited[21][21];
bool block() {
	cnt = 0, rainbow = 0;
	vect.clear();
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j] && arr[i][j]!=9 && arr[i][j]!=-1 && arr[i][j]!=0) {
				visited[i][j] = 1;
				[&]() {
					memset(vvisited, 0, sizeof(vvisited));
					_cnt = 0, _rainbow = 0;
					start = arr[i][j];
					queue<pii> q;
					vector<pii> tmp;
					q.push({ i,j });
					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						
						_cnt++;
						if (arr[y][x] == 9) 
							_rainbow++;
						tmp.push_back({ y,x });
						q.pop();

						for (int k = 0; k < 4; k++) {
							int ddy = y + dy[k];
							int ddx = x + dx[k];

							if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N) {
								if (arr[ddy][ddx] == start && !visited[ddy][ddx]) {
									q.push({ ddy,ddx });
									visited[ddy][ddx] = 1;
								}
								else if (arr[ddy][ddx] == 9 && !vvisited[ddy][ddx]) {
									q.push({ ddy,ddx });
									vvisited[ddy][ddx] = 1;
								}
							}
						}
					}
					if (_cnt > cnt || (_cnt==cnt && _rainbow >= rainbow)) {
						cnt = _cnt;
						rainbow = _rainbow;
						vect.clear();
						for (pii p : tmp)
							vect.push_back(p);
					}
				}();
			}
		}
	}
	return vect.size() >= 2;
}

void gravity() {
	for (int x = 1; x <= N; x++) {
		stack<int> st;
		for (int y = 1; y <= N + 1; y++) {
			if (arr[y][x] > 0) {
				st.push(arr[y][x]);
				arr[y][x] = 0;
			}
			else if (arr[y][x] == -1) {
				int piv = y - 1;
				while (!st.empty()) {
					arr[piv--][x] = st.top();
					st.pop();
				}
			}
		}
	}	
}

int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 0)
					arr[i][j] = 9;
			}
		}
		for (int i = 1; i <= N; i++)
			arr[N + 1][i] = -1;
	}();
	[&]() {
		while (block()) {
			[&]() {
				for (pii p : vect)
					arr[p.first][p.second] = 0;
				point += (int)vect.size() * (int)vect.size();
			}();
			gravity();
			[&]() {
				for (int i = 1, x=1; i <= N; i++, x++) {
					for (int j = 1, y=N; j <= N; j++, y--) 
						cp[y][x] = arr[i][j];
				}
				for (int i = 1; i <= N; i++)
					cp[N + 1][i] = -1;
				copy(&cp[0][0], &cp[21][20], &arr[0][0]);
			}();
			gravity();
		}
	}();
	cout << point;
	return 0;
}