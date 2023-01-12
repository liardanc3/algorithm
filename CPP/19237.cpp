#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;

int N, M, k, tmp, arr[21][21], shark_direct[401], t, m, visited[401], now[21][21];
int shark_direct_priority[401][5][5], smell[21][21], smell_owner[21][21];
int dy[]{ 0,-1,1,0,0 }, dx[]{ 0,0,0,-1,1 };
int main() {
	[&]() {
		cin >> N >> M >> k;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> arr[i][j];
				if (arr[i][j]) {
					smell[i][j] = k;
					smell_owner[i][j] = arr[i][j];
				}
			}
		}
		for (int i = 1; i <= M; i++)
			cin >> shark_direct[i];
		for (int i = 1; i <= M; i++) for (int j = 1; j <= 4; j++) for (int k = 1; k <= 4; k++)
			cin >> shark_direct_priority[i][j][k];
	}();

	[&]() {
		for (t = 1; t <= 1000; t++) {
		/*	for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++)
					cout << arr[i][j] << ' ';
				cout << ' ';
				for (int j = 1; j <= N; j++)
					cout << smell[i][j] << ' ';
				cout << ' ';
				for (int j = 1; j <= N; j++)
					cout << smell_owner[i][j] << ' ';
				cout << '\n';
			}
			cout << "-----------------------------------------\n";*/

			[&]() {
				vect.clear();
				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= N; j++) {
						if (smell[i][j]) {
							vect.push_back({ i,j });
						}
					}
				}
			}();

			[&]() {
				memset(visited, 0, sizeof(visited));
				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= N; j++) {
						int shark = arr[i][j];
						if (shark && visited[shark]) continue;
						visited[shark] = 1;
						if (arr[i][j]) {
							bool flag = true;
							int direct = shark_direct[shark];
							for (int k = 1; k <= 4 && flag; k++) {
								int nd = shark_direct_priority[shark][direct][k];
								int ddy = i + dy[nd];
								int ddx = j + dx[nd];

								if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N && !smell[ddy][ddx]) {
									arr[i][j] = 0;
									if (arr[ddy][ddx] > shark || !arr[ddy][ddx]) {
										arr[ddy][ddx] = shark;
										shark_direct[shark] = nd;
									}
									flag = false;
								}
							}

							// 냄새없는 칸 못찾음
							if (flag) {
								for (int k = 1; k <= 4; k++) {
									int ddy = i + dy[shark_direct_priority[shark][direct][k]];
									int ddx = j + dx[shark_direct_priority[shark][direct][k]];

									if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N && smell[ddy][ddx] && smell_owner[ddy][ddx] == shark) {
										arr[i][j] = 0;
										if (arr[ddy][ddx] > shark || !arr[ddy][ddx]) {
											arr[ddy][ddx] = shark;
											shark_direct[shark] = shark_direct_priority[shark][direct][k];
										}
										break;
									}
								}
							}
						}
					}
				}
			}();

			[&]() {
				// 모든 상어가 자신의 위치에 지속시간 k 냄새를 뿌림
				memset(now, 0, sizeof(now));
				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= N; j++) {
						if (arr[i][j]) {
							smell[i][j] = k;
							smell_owner[i][j] = arr[i][j];
							now[i][j] = 1;
						}
					}
				}
			}();

			[&]() {
				for (pii p : vect) {
					if (now[p.first][p.second])
						continue;
					smell[p.first][p.second]--;
					if (smell[p.first][p.second] == 0)
						smell_owner[p.first][p.second] = 0;
				}
				m = 0;
				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= N; j++) {
						if (arr[i][j] > 1)
							m++;
					}
				}
				if (!m) {
					cout << t;
					exit(0);
				}
			}();

		}
	}();
	cout << -1;
	return 0;
}