#include <bits/stdc++.h>
using namespace std;

int N, M, K, arr[41][41], r, c, sticker[101][11][11], sum, tmp[41][41], stmp[11][11];

bool attach(int y, int x, int idx) {
	copy(&arr[0][0], &arr[40][41], &tmp[0][0]);
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
		
			if (!sticker[idx][i][j]) continue;

			int ddy = i - 1 + y;
			int ddx = j - 1 + x;

			// 스티커 범위 벗어남
			if ((ddy<1 || ddy>N || ddx<1 || ddx>M) && sticker[idx][i][j])
				return false;

			// 스티커 겹침
			if (arr[i - 1 + y][j - 1 + x] && sticker[idx][i][j])
				return false;

			tmp[ddy][ddx] = sticker[idx][i][j];
		}
	}
	copy(&tmp[0][0], &tmp[40][41], &arr[0][0]);
	return true;
}

bool push(int idx) {
	bool flag = false;
	for (int i = 1; i <= N && !flag; i++) {
		for (int j = 1; j <= M && !flag; j++) 
			flag = attach(i, j, idx);
	}
	return flag;
}

void rotate(int idx) {
	memset(stmp, 0, sizeof(stmp));
	int r = 1, c = 1;
	for (int x = 10; x >= 1; x--) {
		for (int y = 1; y <= 10; y++) {
			stmp[y][x] = sticker[idx][r][c];
			c++;
			if (c == 11) {
				r++;
				c = 1;
			}
		}
	}
	int left = 10, top = 10;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (stmp[i][j])
				left = min(left, j), top = min(top, i);
		}
	}
	fill(&sticker[idx][0][0], &sticker[idx][10][11], 0);
	for (int i = top; i <= 10; i++) {
		for (int j = left; j <= 10; j++) {
			if (stmp[i][j])
				sticker[idx][i - top + 1][j - left + 1] = 1;
		}
	}
	return;
}
void init() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= K; i++) {
		cin >> r >> c;
		for (int j = 1; j <= r; j++) {
			for (int k = 1; k <= c; k++)
				cin >> sticker[i][j][k];
		}
	}
}
int main() {
	init();
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < 4; j++) {
			if (push(i)) 
				break;
			if(j!=3) 
				rotate(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			sum += arr[i][j];
	}
	cout << sum;
	return 0;
}