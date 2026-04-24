#include <bits/stdc++.h>
using namespace std;

string tmp;
int N, M, mx, flag[4][4], visited[4][4];
char arr[4][4];
int go(int y, int x) {

	int sum = 0;
	string ss = "";

	// 가로
	if (!flag[y][x]) {
		for (int i = x; i < M && !flag[y][i] && !visited[y][i]; i++) {
			ss += arr[y][i];
			visited[y][i] = 1;
		}
		sum = stoi(ss);
		return sum;
	}

	// 세로
	if (flag[y][x]) {
		for (int i = y; i < N && flag[i][x] && !visited[i][x]; i++) {
			ss += arr[i][x];
			visited[i][x] = 1;
		}
		sum = stoi(ss);
		return sum;
	}

}

void ck() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				sum += go(i, j);
			}
		}
	}
	mx = max(mx, sum);
	return;
}

void dfs(int r, int c, int bit) {
	flag[r][c] = bit;

	if (r == N - 1 && c == M - 1) {
		memset(visited, 0, sizeof(visited));
		ck();
		return;
	}

	int nextR = r;
	int nextC = c;
	nextC++;
	if (nextC == M) {
		nextR++;
		nextC = 0;
	}

	dfs(nextR, nextC, 0);
	dfs(nextR, nextC, 1);
	return;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < M; j++)
			arr[i][j] = tmp[j];
	}
	dfs(0, 0, 0);
	dfs(0, 0, 1);
	cout << mx;
	return 0;
}