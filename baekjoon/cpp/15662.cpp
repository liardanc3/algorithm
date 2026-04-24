#include <bits/stdc++.h>
using namespace std;
int T, saw[1001][8], K, num, cw, cnt, visited[1001];
string tmp;
void rotate(int n, int ccw) {
	visited[n] = 1;

	int __left = saw[n][6];
	int __right = saw[n][2];

	if (ccw == 1) {
		int start = saw[n][0];
		for (int i = 0; i < 7; i++) {
			int next = i + 1;
			saw[n][i] = saw[n][next];
		}
		saw[n][7] = start;
	}
	else {
		int start = saw[n][7];
		for (int i = 7; i > 0; i--) {
			int next = i - 1;
			saw[n][i] = saw[n][next];
		}
		saw[n][0] = start;
	}

	int _left = n - 1;
	int _right = n + 1;

	if (_left > 0 && saw[_left][2] != __left && !visited[_left])
		rotate(_left, -ccw);
	if (_right <= T && saw[_right][6] != __right && !visited[_right])
		rotate(_right, -ccw);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> tmp;
		for (int j = 0; j < 8; j++)
			saw[i][j] = tmp[j]-'0';
	}
	cin >> K;
	while (K--) {
		cin >> num >> cw;
		rotate(num, -cw);
		memset(visited, 0, sizeof(visited));
	}
	for (int i = 1; i <= T; i++) {
		if (saw[i][0])
			cnt++;
	}
	cout << cnt;
	return 0;
}