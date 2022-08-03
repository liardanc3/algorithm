#include <bits/stdc++.h>
using namespace std;

int N, arr[11][11], mx1, mx2;
void dfs(int y, int x, int cnt, int start) {
	if (y == N && x > N) {
		start == 1 ? mx1 = max(mx1, cnt) : mx2 = max(mx2, cnt);
		return;
	}
		
	if (x > N) {
		y++;
		if (start == 1)
			x = 2, start = 2;
		else
			x = 1, start = 1;
	}

	if (arr[y][x] != 1)
		dfs(y, x + 2, cnt, start);

	else {
		int leftup = 1;
		for (int i = y - 1, j = x - 1; 1 <= i && 1 <= j && leftup; i--, j--) {
			if (arr[i][j] == 2)
				leftup = 0;
		}
		int rightup = 1;
		for (int i = y - 1, j = x + 1; 1 <= i && j <= N && rightup; i--, j++) {
			if (arr[i][j] == 2)
				rightup = 0;
		}

		if (leftup && rightup) {
			arr[y][x] = 2;
			dfs(y, x + 2, cnt + 1, start);
			arr[y][x] = 1;
		}

		dfs(y, x + 2, cnt, start);
	}
	return;
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) 
				cin >> arr[i][j];
		}
	}();
	dfs(1, 1, 0, 1);
	dfs(1, 2, 0, 2);
	cout << mx1 + mx2;
	return 0;
}