#include <bits/stdc++.h>
using namespace std;
int N, M;
char board[51][51];
string tmp;

int count(char color, int y, int x) {
	int cnt = 0;
	bool odd = (y + x) % 2;

	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			bool _odd = (i + j) % 2;
			if (odd == _odd && color != board[i][j])
				cnt++;
			else if (odd != _odd && color == board[i][j])
				cnt++;
		}
	}
	return cnt;
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		for (int j = 1; j <= M; j++) {
			board[i][j] = tmp[j - 1];
		}
	}
	int mn = 1e9;
	for (int i = 1; i + 7 <= N; i++) for (int j = 1; j + 7 <= M; j++) {
		mn = min(mn, min(count('W', i, j), count('B', i, j)));
	}
	cout << mn;
	return 0;
}