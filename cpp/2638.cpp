#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int arr[101][101], N, M, tmp;
int dy[]{ -1,0,0,1 };
int dx[]{ 0,-1,1,0 };
queue<pii> Q;
void bfs(int yy,int xx) {
	queue<pii> q;
	q.push(pii(yy,xx));
	arr[yy][xx] = -1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int ddy = y + dy[i];
			int ddx = x + dx[i];
			if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= M && arr[ddy][ddx] == 0) {
				arr[ddy][ddx] = -1;
				q.push(pii(ddy, ddx));
			}
		}
	}
}

int cheese() {
	int cnt = 0;
	while (!Q.empty()) {
		cnt++;
		int size = Q.size();
		queue<pii> tmp;
		while (size--) {
			int y = Q.front().first;
			int x = Q.front().second;
			int out_check = 0;
			for (int i = 0; i < 4; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];
				if (arr[ddy][ddx] == -1)
					out_check++;
			}
			if (out_check >= 2) {
				tmp.push(pii(y, x));
				Q.pop();
			}
			else {
				Q.push(Q.front());
				Q.pop();
			}
		}
		while (!tmp.empty()) {
			bfs(tmp.front().first, tmp.front().second);
			tmp.pop();
		}
	}
	return cnt;
}
void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> tmp; arr[i][j] = tmp;
			if (tmp == 1)
				Q.push(pii(i, j));
		}
	} bfs(1, 1);
}
int main() {
	input();
	cout << cheese();
	return 0;
}