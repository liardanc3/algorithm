#include <bits/stdc++.h>
using namespace std;
int R, C, T, up, down;
int arr[51][51];
int tmp[51][51];
int dy[]{ -1,0,0,1 };
int dx[]{ 0,-1,1,0 };
void spread() {
	memset(tmp, 0, sizeof(tmp));
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j] == -1) continue;
			int start = arr[i][j];
			int div = arr[i][j] / 5;
			if (start != 0) {
				for (int k = 0; k < 4; k++) {
					int y = i + dy[k];
					int x = j + dx[k];

					if (1 <= y && y <= R && 1 <= x && x <= C && arr[y][x] != -1) {
						tmp[y][x] += div;
						arr[i][j] -= div;
					}
				}
			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)
			arr[i][j] += tmp[i][j];
	}
}
void cleaner() {
	for (int i = up-1; i >= 2; i--) 
		arr[i][1] = arr[i-1][1];
	for (int i = 1; i <= C-1; i++)
		arr[1][i] = arr[1][i + 1];
	for (int i = 1; i <= up-1; i++)
		arr[i][C] = arr[i + 1][C];
	for (int i = C; i >= 3; i--)
		arr[up][i] = arr[up][i - 1];
	arr[up][2] = 0;

	for (int i = down +1; i <= R - 1; i++)
		arr[i][1] = arr[i + 1][1];
	for (int i = 1; i <= C - 1; i++)
		arr[R][i] = arr[R][i + 1];
	for (int i = R; i >= down+1; i--)
		arr[i][C] = arr[i - 1][C];
	for (int i = C; i >= 3; i--)
		arr[down][i] = arr[down][i - 1];
	arr[down][2] = 0;
}

void input() {
	cin >> R >> C >> T;
	up = 0; down = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				if (up == 0)
					up = i;
				else down = i;
			}
		}
	}
}

int cnt() {
	int sum = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j] != -1)
				sum += arr[i][j];
		}
	}
	return sum;
}
int main() {
	input();
	while (T--) {
		spread();
		cleaner();
	}
	
	cout << cnt();
	return 0;
}