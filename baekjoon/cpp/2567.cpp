#include <bits/stdc++.h>
using namespace std;

int N, x, y, arr[101][101], cnt;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> x >> y;
		for (int i = x; i < x + 10 && i < 100; i++) {
			for (int j = y; j < y + 10 && j < 100; j++)
				arr[i][j] = 1;
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 0)
				continue;
			for (int k = 0; k < 4; k++) {
				int y = i + dy[k];
				int x = j + dx[k];

				if (0 <= y && y < 100 && 0 <= x && x < 100 && arr[y][x] == 0)
					cnt++;
				else if (y == -1 || y == 100 || x == -1 || x == 100)
					cnt++;
			}
		}
	}

	cout << cnt;
	return 0;
}
