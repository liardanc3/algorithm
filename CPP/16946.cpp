#include <bits/stdc++.h>
using namespace std;
int N, M, arr[1001][1001]{ 0, }, res[1001][1001]{ 0, }, zero[1001][1001]{ 0, };
int tree[1001][1001];
int ck[1000 * 1000 + 1]{ 0, };
int dy[]{ -1,0,0,1 };
int dx[]{ 0,-1,1,0 };
string tmp;
typedef pair<int, int> pii;
void zero_bfs(int yy, int xx) {
	int cnt = 1;
	queue<pii> q;
	stack<pii> s;
	s.push({ yy,xx });
	q.push({ yy,xx });
	tree[yy][xx] = (yy - 1) * M + xx;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ddy = y + dy[i];
			int ddx = x + dx[i];
			if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= M && tree[ddy][ddx]==0 && arr[ddy][ddx]==0) {
				cnt++;
				q.push({ ddy,ddx });
				s.push({ ddy,ddx });
				tree[ddy][ddx] = (yy - 1) * M + xx;
			}
		}
	}
	while (!s.empty()) {
		int y = s.top().first;
		int x = s.top().second;
		zero[y][x] = cnt;
		s.pop();
	}
	return;
}
int bfs(int i, int j) {
	map<int, int> m;
	int cnt = 1;
	int y = i;
	int x = j;
	for (int i = 0; i < 4; i++) {
		int ddy = y + dy[i];
		int ddx = x + dx[i];
		if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= M && arr[ddy][ddx] == 0 && m[tree[ddy][ddx]]==0) {
			cnt += zero[ddy][ddx];
			m[tree[ddy][ddx]] = 1;
		}
	}
	return cnt;
}
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			arr[i + 1][j + 1] = tmp.at(j) - '0';
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (zero[i][j] == 0 && arr[i][j] == 0)
				zero_bfs(i, j);
		}
	}
}
int main() {
	
	init();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 0)
				cout << 0;
			else
				cout << bfs(i, j) % 10;
		}
		cout << '\n';
	}
	return 0;
}