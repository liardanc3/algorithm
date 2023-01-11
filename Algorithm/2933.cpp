#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;

char arr[101][101];
string tmp;
int R, C, N, h, visited[101][101];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
void print() {
	for (int i = R; i >= 1; i--) {
		for (int j = 1; j <= C; j++)
			cout << arr[i][j];
		cout << '\n';
	}
}
void gravity() {
	memset(visited, 0, sizeof(visited));
	for (int i = R; i >= 1; i--) {
		for (int j = 1; j <= C; j++) {
			if (!visited[i][j] && arr[i][j]=='x') {
				bool flag = false;
				[&]() {
					vect.clear();
					queue<pii> q;
					q.push({ i,j });
					visited[i][j] = 1;
					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						
						q.pop();
						arr[y][x] = '.';
						vect.push_back({ y,x });

						for (int k = 0; k < 4; k++) {
							int ddy = y + dy[k];
							int ddx = x + dx[k];

							if (1 <= ddy && ddy <= R && 1 <= ddx && ddx <= C && !visited[ddy][ddx] && arr[ddy][ddx] == 'x') {
								q.push({ ddy,ddx });
								visited[ddy][ddx] = 1;
							}
						}
					}
					int mny = 1e9;
					for (int k = 0; k < vect.size(); k++) {
						int y = vect[k].first;
						int x = vect[k].second;

						int cnt = 0;
						while (arr[y][x] == '.' && y != 0)
							y--, cnt++;

						mny = min(mny, cnt-1);
					}
					for (pii p : vect) 
						arr[p.first - mny][p.second] = 'x';
					if (mny != 0)
						flag = true;
				}();
				if(flag)
					return;
			}
		}
	}
}
void stick(int odd) {
	if (odd) {
		for (int i = 1; i <= C; i++) {
			if (arr[h][i] == 'x') {
				arr[h][i] = '.';
				gravity();
				break;
			}
		}
	}
	else {
		for (int i = C; i >= 1; i--) {
			if (arr[h][i] == 'x') {
				arr[h][i] = '.';
				gravity();
				break;
			}
		}
	}
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> R >> C;
		for (int i = R; i >= 1; i--) {
			cin >> tmp;
			for (int j = 1; j <= C; j++)
				arr[i][j] = tmp[j - 1];
		}
	}();
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> h;
		stick(i % 2);
	}
	print();
	return 0;
}