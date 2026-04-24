#include <bits/stdc++.h>
using namespace std;

int N, M, arr[999][999], y, x, start, sy, sx, idx;
int dy[]{ 1,0,-1,0 }, dx[]{ 0,1,0,-1 };
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	start = N * N;
	for (int i = 0; i < N * N; i++) {
		if (start == M)
			y = sy, x = sx;
		arr[sy][sx] = start--;
		if (sy + dy[idx] < 0 || sy + dy[idx] >= N ||
			sx + dx[idx] < 0 || sx + dx[idx] >= N ||
			arr[sy + dy[idx]][sx + dx[idx]] != 0)
			idx = (idx + 1) % 4;
		sy += dy[idx], sx += dx[idx];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
	cout << y+1 << ' ' << x+1;
	return 0;
}