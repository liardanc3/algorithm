#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, K, arr[11][11], mx = -10001;
int visited[11][11]{ 0, };
int dy[]{ -1,0,0,1 };
int dx[]{ 0,-1,1,0 };
pii vect[4];
void bt(int start, int now) {
	if (now == K) {
		int sum = 0;
		for (int i = 0; i < now; i++) 
			sum += arr[vect[i].first][vect[i].second];
		mx = max(mx, sum);
		return;
	}
	for (int y = start; y <= N*M; y++) {
		int i = y / M + 1;
		if (y % M == 0) i--;
		int j = y % M;
		if (y % M == 0) j = M;
		bool flag = true;
		if (visited[i][j]) continue;
		for (int k = 0; k < 4; k++) {
			int y = i + dy[k];
			int x = j + dx[k];
			if (1 <= y && y <= N && 1 <= x && x <= M) {
				if (visited[y][x]) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			visited[i][j] = 1;
			vect[now] = { i,j };
			bt(y+1, now+1);
			visited[i][j] = 0;
		}
	}
	return;
}
int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
		cin >> arr[i][j];
	}
	bt(1, 0);
	cout << mx;

	return 0;
}