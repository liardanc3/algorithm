#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, L, R, arr[51][51], day = 0, visited[51][51];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
int f() {
	int flag = 0;
	memset(visited, 0, sizeof(visited));
	vector<pii> vect[51][51];
	
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {

			
			for (int k = 0; k < 4; k++) {
				int ddy = y + dy[k];
				int ddx = x + dx[k];

				if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N) {
					if (L <= abs(arr[y][x] - arr[ddy][ddx]) && abs(arr[y][x] - arr[ddy][ddx]) <= R) {
						flag = 1;
						vect[y][x].push_back({ ddy,ddx });
						vect[ddy][ddx].push_back({ y,x });
		
					}
				}
			}

		}
	}
	if (!flag) return flag;
	memset(visited, 0, sizeof(visited));
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (visited[y][x]) continue;
			visited[y][x] = 1;
			int sum = 0, cnt = 0;
			vector<pii> __vect__;
			__vect__.push_back({ y,x });
			queue<pii> q;
			q.push({ y,x });
			while (!q.empty()) {
				pii now = q.front();
				q.pop();

				visited[now.first][now.second] = 1;
				cnt++;
				sum += arr[now.first][now.second];

				for (pii p : vect[now.first][now.second]) {
					if (visited[p.first][p.second]) continue;
					
					visited[p.first][p.second] = 1;
					q.push(p);
					__vect__.push_back(p);
				}
			}
			for (pii p : __vect__) 
				arr[p.first][p.second] = sum / cnt;
		}
	}
	return flag;
}
int main() {
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
		cin >> arr[i][j];
	while (true) {
		int ret = f();
		if (!ret) break;
		day++;
	}
	cout << day;
	return 0;
}