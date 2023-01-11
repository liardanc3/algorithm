#include <bits/stdc++.h>
using namespace std;

int R, C, cnt, mx;
string tmp;
char arr[10001][501];
int dfs(int y, int x) {
	arr[y][x] = 'x';
	int ret = 0;
	if (x == C)
		return 1;

	if (y - 1 >= 1 && arr[y - 1][x+1] == '.') {
		ret = dfs(y - 1, x+1);
	}
		
	if (!ret && arr[y][x + 1] == '.') {
		ret = dfs(y, x + 1);
	}

	if (!ret && y +1 <= R && arr[y + 1][x + 1] == '.') {
		ret = dfs(y + 1, x + 1);
	}

	return ret;
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> R >> C;
		for (int i = 1; i <= R; i++) {
			cin >> tmp;
			for (int j = 1; j <= C; j++)
				arr[i][j] = tmp[j - 1];
		}
	}();
	[&]() {
		for (int i = 1; i <= R; i++)
			cnt += dfs(i, 1);
		cout << cnt;
	}();
	return 0;
}