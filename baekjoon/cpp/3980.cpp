#include <bits/stdc++.h>
using namespace std;
int c, visited[11], mx, arr[11][11];
vector<int> vect[11];

void dfs(int idx, int sum) {
	if (idx == 11) {
		mx = max(mx, sum);
		return;
	}
	for (int i = 0; i < vect[idx].size(); i++) {
		int next = vect[idx][i];
		if (!visited[next]) {
			visited[next] = 1;
			dfs(idx + 1, sum + arr[next][idx]);
			visited[next] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> c;
	while (c--) {
		mx = 0;
		for (int i = 0; i < 11; i++)
			vect[i].clear();
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> arr[i][j];
				if (arr[i][j] > 0)
					vect[j].push_back(i);
			}
		}
		dfs(0, 0);
		cout << mx << '\n';
	}
	return 0;
}