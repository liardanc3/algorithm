#include <bits/stdc++.h>
using namespace std;
int arr[25][25], ck[25][25], ans;

int dfs(int row, int col) {
	ck[row][col] = 1; ans++;
	if (row + 1 <= 24 && ck[row + 1][col] == 0 && arr[row + 1][col] == 1) dfs(row + 1, col);
	if (row - 1 >= 0 && ck[row - 1][col] == 0 && arr[row - 1][col] == 1) dfs(row - 1, col);
	if (col + 1 <= 24 && ck[row][col + 1] == 0 && arr[row][col + 1] == 1) dfs(row, col + 1);
	if (col - 1 >= 0 && ck[row][col - 1] == 0 && arr[row][col - 1] == 1) dfs(row, col - 1);
	return ans;
}

int main() {
	memset(ck, 0, sizeof(ck));
	memset(arr, 0, sizeof(arr));
	int N; string tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < N; j++)
			arr[i][j] = tmp[j]-'0';
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = 0;
			if (arr[i][j] == 1 && ck[i][j] == 0) {
				dfs(i, j); pq.push(ans);
			}
		}
	}
	cout << pq.size() << '\n';
	while(!pq.empty()) {
		cout << pq.top() << '\n'; pq.pop();
	}
	return 0;
}