#include <bits/stdc++.h>
//#define int long long
using namespace std;

typedef pair<int, int> pii;

int R, C, visited[251][251], S, W;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1, 0 };
char arr[251][251];
string tmp;

void bfs(int yy, int xx) {
	int sheep = 0, wolf = 0;
	queue<pii> q;
	q.push({ yy,xx });
	visited[yy][xx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (arr[y][x] == 'v') wolf++;
		if (arr[y][x] == 'o') sheep++;

		for (int i = 0; i < 4; i++) {
			int ddy = y + dy[i];
			int ddx = x + dx[i];

			if (1 <= ddy && ddy <= R && 1 <= ddx && ddx <= C && !visited[ddy][ddx] && arr[ddy][ddx] != '#') {
				visited[ddy][ddx] = 1;
				q.push({ ddy,ddx });
			}
		}
	}
	if (sheep > wolf) 
		S += sheep;
	else 
		W += wolf;
	return;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		cin >> tmp;
		for (int j = 1; j <= C; j++)
			arr[i][j] = tmp[j - 1];
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (!visited[i][j] && arr[i][j] != '#')
				bfs(i, j);
		}
	}
	cout << S << ' ' << W;
	return 0;
}