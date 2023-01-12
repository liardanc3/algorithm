#include <bits/stdc++.h>
using namespace std;
int N;
char board[51][51];
int mxcheck(int y, int x) {
	int mx = 1;
	int cnt1 = 1, cnt2 = 1;
	for (int i = 1; i <= N-1; i++) {
		if (board[i+1][x] == board[i][x]) {
			cnt1++;
		}
		else if (board[i+1][x] != board[i][x]) {
			mx = max(mx, cnt1);
			cnt1 = 1;
		}

		if (board[y][i+1] == board[y][i]) {
			cnt2++;
		}
		else if (board[y][i+1] != board[y][i]) {
			mx = max(mx, cnt2);
			cnt2 = 1;
		}
	}
	return max(mx, max(cnt1, cnt2));
}
int dy[]{ -1,0,0,1 };
int dx[]{ 0,-1,1,0 };
void bf() {
	int mx = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int y = i;
			int x = j;
			for (int k = 0; k < 4; k++) {
				int ddy = y + dy[k];
				int ddx = x + dx[k];
				if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N) {
					swap(board[y][x], board[ddy][ddx]);
					mx = max(mx, mxcheck(y,x));
					swap(board[y][x], board[ddy][ddx]);
				}
			}
		}
	}
	cout << mx;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
		cin >> board[i][j];
	}
	bf();
	return 0;
}