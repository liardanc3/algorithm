#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int ans, dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 }, visited[12][6], cnt, flag;
char arr[12][6], token;
void bfs(int i, int j) {
	cnt = 1;
	token = arr[i][j];
	visited[i][j] = 1;
	queue<pii> q;
	vector<pii> vect;
	vect.push_back({ i,j });
	q.push({ i,j });
	while (!q.empty()) {
		pii now = q.front(); q.pop();
		int y = now.first;
		int x = now.second;

		for (int k = 0; k < 4; k++) {

			int ddy = y + dy[k];
			int ddx = x + dx[k];

			if (0 <= ddy && ddy < 12 && 0 <= ddx && ddx < 6 && !visited[ddy][ddx] && arr[ddy][ddx] == token) {
				visited[ddy][ddx] = 1;
				q.push({ ddy,ddx });
				cnt++;
				vect.push_back({ ddy,ddx });
			}
		}
	}
	if (cnt >= 4) {
		for (pii p : vect)
			arr[p.first][p.second] = '.';
		if (flag) ans++;
		flag = 0;
	}
}
void down() {
	stack<char> st;
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 12; y++) {
			if (arr[y][x] != '.')
				st.push(arr[y][x]);
			arr[y][x] = '.';
		}
		for (int y = 11; !st.empty(); y--) {
			arr[y][x] = st.top();
			st.pop();
		}
	}
}
void init() {
	for (int i = 0; i < 12; i++) for (int j = 0; j < 6; j++)
		cin >> arr[i][j];
}
void go() {
	memset(visited, 0, sizeof(visited));
	flag = 1;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (!visited[i][j] && arr[i][j] != '.')
				bfs(i, j);
		}
	}
}
int main() {
	init();
	while(true) {
		int tmp = ans;
		go();
		down();
		if (tmp == ans) break;
	}
	cout << ans;
	return 0;
}