#include <bits/stdc++.h>
using namespace std;

int arr[10000][6], n, mx, topArr[10000];
map<int, int> rev;

// case1 : 1 2 3 4 (head = 0,5)
// case2 : 0 2 5 4 (head = 1,3)
// case3 : 0 1 3 5 (head = 2,4)

void dfs(int top, int level) {
	if (level == n - 1) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int _top = topArr[i];

			if (_top == 0 || _top == 5) 
				sum += max(max(arr[i][1], arr[i][2]), max(arr[i][3], arr[i][4]));
			if (_top == 1 || _top == 3)
				sum += max(max(arr[i][0], arr[i][2]), max(arr[i][5], arr[i][4]));
			if (_top == 2 || _top == 4)
				sum += max(max(arr[i][0], arr[i][1]), max(arr[i][3], arr[i][5]));

		}
		mx = max(mx, sum);
		return;
	}

	int bot_idx, top_idx;
	for (int i = 0; i < 6; i++) {
		if (arr[level + 1][i] == arr[level][top]) {
			bot_idx = i;
			break;
		}
	}
	top_idx = rev[bot_idx];

	topArr[level + 1] = top_idx;
	dfs(top_idx, level + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	rev[0] = 5, rev[1] = 3, rev[2] = 4, rev[3] = 1, rev[4] = 2, rev[5] = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++)
			cin >> arr[i][j];
	}
	topArr[0] = 0, dfs(0, 0);
	topArr[0] = 1, dfs(1, 0);
	topArr[0] = 2, dfs(2, 0);
	topArr[0] = 3, dfs(3, 0);
	topArr[0] = 4, dfs(4, 0);
	topArr[0] = 5, dfs(5, 0);
	cout << mx;
	return 0;
}