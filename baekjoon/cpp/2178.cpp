#include <bits/stdc++.h>
#define INF 999999
using namespace std;
int** gr;
queue<pair<int, int>> q;

int bfs(int row, int col,int N, int M) {
	if (row == N && col == M) return 0;
	if (row - 1 >= 0 && gr[row - 1][col] == INF && gr[row - 1][col] != 0) {
		q.push(pair<int, int>(row - 1, col)); gr[row - 1][col] = min(gr[row - 1][col], gr[row][col] + 1);
	}
	if (row + 1 <= N - 1 && gr[row+1][col] == INF && gr[row + 1][col] != 0) {
		q.push(pair<int, int>(row + 1, col)); gr[row + 1][col] = min(gr[row + 1][col], gr[row][col] + 1);
	}
	if (col - 1 >= 0 && gr[row][col-1] == INF && gr[row][col - 1] != 0) {
		q.push(pair<int, int>(row, col - 1)); gr[row][col - 1] = min(gr[row][col - 1], gr[row][col] + 1);
	}
	if (col + 1 <= M - 1 && gr[row][col+1] == INF && gr[row][col + 1] != 0) {
		q.push(pair<int, int>(row, col + 1)); gr[row][col + 1] = min(gr[row][col + 1], gr[row][col] + 1);
	}
	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		bfs(tmp.first, tmp.second, N, M);
	}
	return 0;
}

int main() {
	int N, M; string tmp;
	cin >> N >> M;
	gr = new int* [N];
	for (int i = 0; i < N; i++) {
		gr[i] = new int[M];
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			if (tmp[j] == '1') gr[i][j] = INF;
		}
	} gr[0][0] = 1;
	bfs(0, 0, N, M);
	cout << gr[N-1][M-1];
	return 0;
}