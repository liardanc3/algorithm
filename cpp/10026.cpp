#include <bits/stdc++.h>
using namespace std;
char pic[100][100];
int ck[100][100];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int dfs(char color,int y,int x) {
	ck[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int Y = y + dy[i];
		int X = x + dx[i];
		if (X >= 0 && X < 100 && Y >= 0 && Y < 100 && ck[Y][X] == 0 && pic[Y][X] == color)
			dfs(color, Y, X);
	}
	return 1;
}

int main() {
	int N; cin >> N;
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			pic[i][j] = tmp[j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (ck[i][j] == 0) {
				cnt += dfs(pic[i][j], i, j);
			}
		}
	} cout << cnt << ' ';
	cnt = 0; memset(ck, 0, sizeof(ck));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (pic[i][j] == 'G') pic[i][j] = 'R';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (ck[i][j] == 0) {
				cnt += dfs(pic[i][j], i, j);
			}
		}
	} cout << cnt;
	return 0;
}