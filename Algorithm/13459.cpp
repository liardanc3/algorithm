#include <bits/stdc++.h>
using namespace std;

int N, M, visited[4][11];
char arr[10][10];
string tmp;
void dfs(int dist, int bef, int cnt) {
	if (cnt > 10)
		return;
	char ttmp[10][10];
	copy(&arr[0][0], &arr[9][10], &ttmp[0][0]);


	if ((dist == 1 || dist == -1) && bef != 1 && bef != 2) {
		for (int y = 1; y < N - 1; y++) {
			stack<char> q;
			for (int x = M - 2; x >= 0; x--) {
				if (arr[y][x] != '#' && arr[y][x] != '.' && arr[y][x] != 'O') {
					q.push(arr[y][x]);
					arr[y][x] = '.';
				}
				else if (arr[y][x] == '.') continue;
				else {
					int left = x + 1;
					int red = 0, blue = 0;
					while (!q.empty()) {
						if (arr[y][x] == 'O') {
							if (q.top() == 'R')
								red = 1;
							else
								blue = 1;
						}
						else
							arr[y][left++] = q.top();
						q.pop();
					}
					if (red && !blue) {
						cout << 1;
						exit(0);
					}
					if (blue) {
						copy(&ttmp[0][0], &ttmp[9][10], &arr[0][0]);
						return;
					}
				}
			}
		}
		int tttmp[10][10];
		copy(&arr[0][0], &arr[9][10], &tttmp[0][0]);
		for (int i = 1; i <= 4; i++) {
			dfs(i, 1, cnt + 1);
			copy(&tttmp[0][0], &tttmp[9][10], &arr[0][0]);
		}
		copy(&ttmp[0][0], &ttmp[9][10], &arr[0][0]);
	}

	if ((dist == 2 || dist == -1) && bef != 2 && bef != 1) {
		for (int y = 1; y < N - 1; y++) {
			stack<char> q;
			for (int x = 1; x <= M - 1; x++) {
				if (arr[y][x] != '#' && arr[y][x] != '.' && arr[y][x] != 'O') {
					q.push(arr[y][x]);
					arr[y][x] = '.';
				}
				else if (arr[y][x] == '.') continue;
				else {
					int right = x - 1;
					int red = 0, blue = 0;
					while (!q.empty()) {
						if (arr[y][x] == 'O') {
							if (q.top() == 'R')
								red = 1;
							else
								blue = 1;
						}
						else
							arr[y][right--] = q.top();
						q.pop();
					}
					if (!red || !blue) {
						if (red && !blue) {
							cout << 1;
							exit(0);
						}
						if (blue) {
							copy(&ttmp[0][0], &ttmp[9][10], &arr[0][0]);
							return;
						}
					}
				}
			}
		}
		int tttmp[10][10];
		copy(&arr[0][0], &arr[9][10], &tttmp[0][0]);
		for (int i = 1; i <= 4; i++) {
			dfs(i, 2, cnt + 1);
			copy(&tttmp[0][0], &tttmp[9][10], &arr[0][0]);
		}
		copy(&ttmp[0][0], &ttmp[9][10], &arr[0][0]);
	}

	if ((dist == 3 || dist == -1) && bef != 3 && bef != 4) {
		for (int x = 1; x < M; x++) {
			stack<char> q;
			for (int y = N - 2; y >= 0; y--) {
				if (arr[y][x] != '#' && arr[y][x] != '.' && arr[y][x] != 'O') {
					q.push(arr[y][x]);
					arr[y][x] = '.';
				}
				else if (arr[y][x] == '.') continue;
				else {
					int up = y + 1;
					int red = 0, blue = 0;
					while (!q.empty()) {
						if (arr[y][x] == 'O') {
							if (q.top() == 'R')
								red = 1;
							else
								blue = 1;
						}
						else
							arr[up++][x] = q.top();
						q.pop();
					}
					if (!red || !blue) {
						if (red && !blue) {
							cout << 1;
							exit(0);
						}
						if (blue) {
							copy(&ttmp[0][0], &ttmp[9][10], &arr[0][0]);
							return;
						}
					}
					up = y - 1;
				}
			}
		}
		int tttmp[10][10];
		copy(&arr[0][0], &arr[9][10], &tttmp[0][0]);
		for (int i = 1; i <= 4; i++) {
			dfs(i, 3, cnt + 1);
			copy(&tttmp[0][0], &tttmp[9][10], &arr[0][0]);
		}
		copy(&ttmp[0][0], &ttmp[9][10], &arr[0][0]);
	}

	if ((dist == 4 || dist == -1) && bef != 4 && bef != 3) {
		for (int x = 1; x < M; x++) {
			stack<char> st;
			for (int y = 1; y <= N - 1; y++) {
				if (arr[y][x] != '#' && arr[y][x] != '.' && arr[y][x] != 'O') {
					st.push(arr[y][x]);
					arr[y][x] = '.';
				}
				else if (arr[y][x] == '.') continue;
				else {
					int down = y - 1;
					int red = 0, blue = 0;
					while (!st.empty()) {
						if (arr[y][x] == 'O') {
							if (st.top() == 'R')
								red = 1;
							else
								blue = 1;
						}
						else
							arr[down--][x] = st.top();
						st.pop();
					}
					if (!red || !blue) {
						if (red && !blue) {
							cout << 1;
							exit(0);
						}
						if (blue) {
							copy(&ttmp[0][0], &ttmp[9][10], &arr[0][0]);
							return;
						}
					}
				}
			}
		}
		int tttmp[10][10];
		copy(&arr[0][0], &arr[9][10], &tttmp[0][0]);
		for (int i = 1; i <= 4; i++) {
			dfs(i, 4, cnt + 1);
			copy(&tttmp[0][0], &tttmp[9][10], &arr[0][0]);
		}
		copy(&ttmp[0][0], &ttmp[9][10], &arr[0][0]);
	}
	return;
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			for (int j = 0; j < M; j++)
				arr[i][j] = tmp[j];
		}
	}();
	for (int i = 1; i <= 4; i++)
		dfs(i, 0, 1);
	cout << 0;
	return 0;
}