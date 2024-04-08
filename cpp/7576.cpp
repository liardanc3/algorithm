#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
queue<pii> Q;
int dx[] = { 1,0,-1 ,0};
int dy[] = { 0,1,0, -1};
int bfs(int **arr,int N, int M) {
	int cnt = -1;
	while (!Q.empty()) {
		cnt++;
		int size = Q.size();
		for (int i = 0; i < size; i++) {
			pii tmp_pair = Q.front(); Q.pop();
			for (int j = 0; j < 4; j++) {
				int y = tmp_pair.first + dy[j];
				int x = tmp_pair.second + dx[j];
				if (x >= 0 && x < M && y >= 0 && y < N && arr[y][x] == 0) {
					Q.push(pii(y, x)); arr[y][x] = 1;
				}
			}
		}
	}
	int check = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				check = 1; break;
			}
		}
	}
	if (check == 1) return -1;
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	int N, M, tmp;
	cin >> M >> N;
	int** arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[M];
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			arr[i][j] = tmp;
			if (tmp == 1) Q.push(pii(i,j));
		}
	}
	cout << bfs(arr,N,M);
	return 0;
}