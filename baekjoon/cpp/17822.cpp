#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N, M, T, arr[51][51], x, d, k, visited[51][51], flag, ans;
int dx[]{ -1,1,0 ,0 }, dy[]{ 0,0,-1,1 };

void bfs(int yy, int xx) {
	vector<pii> vect;
	vect.push_back({ yy,xx });
	visited[yy][xx] = 1;
	int token = arr[yy][xx];
	if (token==-1e9) return;
	queue<pii> q;
	q.push({ yy,xx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ddy = y + dy[i];
			int ddx = x + dx[i];

			if (ddx == 0) ddx = M;
			if (ddx == M + 1) ddx = 1;

			if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= M && arr[ddy][ddx] == token && !visited[ddy][ddx]) {
				vect.push_back({ ddy,ddx });
				q.push({ ddy,ddx });
				visited[ddy][ddx] = 1;
			}
		}
	}
	if (vect.size() > 1) {
		for (pii p : vect)
			arr[p.first][p.second] = -1e9;
		flag = 1;
	}
	return;
}

void rotate() {
	flag = 0;
	memset(visited, 0, sizeof(visited));
	while (k--) {
		for (int i = x; i <= N; i += x) {
			if (!d) {
				vector<int> vect;
				vect.push_back(arr[i][M]);
				for (int j = 1; j < M; j++)
					vect.push_back(arr[i][j]);
				for (int j = 1; j <= M; j++)
					arr[i][j] = vect[j - 1];
			}
			else {
				vector<int> vect;
				for (int j = 2; j <= M; j++)
					vect.push_back(arr[i][j]);
				vect.push_back(arr[i][1]);
				for (int j = 1; j <= M; j++)
					arr[i][j] = vect[j - 1];
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visited[i][j])
				bfs(i, j);
		}
	}

	if (!flag) {
		double sum = 0, cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (arr[i][j] != -1e9) {
					sum += arr[i][j];
					cnt++;
				}
			}
		}
		double avg = sum / cnt;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (arr[i][j] != -1e9) {
					if ((double)arr[i][j] > avg)
						arr[i][j] -= 1;
					else if(double(arr[i][j]) < avg)
						arr[i][j] += 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++)
		cin >> arr[i][j];
	while (T--) {
		cin >> x >> d >> k;
		rotate();
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] != -1e9)
				ans += arr[i][j];
		}
	}
	cout << ans;
	return 0;
}