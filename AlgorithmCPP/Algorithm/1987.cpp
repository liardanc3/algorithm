#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int R, C, ck[26], mx;
char arr[21][21];
int dy[]{ -1,0,0,1 };
int dx[]{ 0,-1,1,0 };
void dfs(int y,int x, int cnt) {
	mx = max(mx, cnt);
	for (int i = 0; i < 4; i++) {
		int ddy = y + dy[i];
		int ddx = x + dx[i];
		int ascii = arr[ddy][ddx] - 'A';

		if (1 <= ddy && ddy <= R && 1 <= ddx && ddx <= C) {

			if (ck[ascii] == 0) {
				ck[ascii] = 1;
				dfs(ddy, ddx, cnt + 1);
				ck[ascii] = 0;
			}
		}
	}
}

int main() {
	string tmp; mx = 0;
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		cin >> tmp;
		for (int j = 1; j <= tmp.size(); j++) {
			arr[i][j] = tmp.at(j - 1);
		}
	}
	int ascii = arr[1][1] - 'A';
	ck[ascii] = 1;
	dfs(1,1,1);
	cout << mx;

	return 0;
}