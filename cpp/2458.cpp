#include <bits/stdc++.h>

using namespace std;
int N, M, a, b, cnt, sum, visited[501];

vector<int> L[501], R[501];

void dfs(int num, int left, int right) {
	if (left) {
		for (int _L : L[num]) {
			if (!visited[_L]) {
				visited[_L] = 1;
				sum++;
				dfs(_L, left, right);

			}

		}
	}
	if (right) {
		for (int _R : R[num]) {
			if (!visited[_R]) {
				visited[_R] = 1;
				sum++;
				dfs(_R, left, right);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		L[b].push_back(a);
		R[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		sum = 0;
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		dfs(i, 1, 0);
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		dfs(i, 0, 1);
		if (sum == N - 1) cnt++;
	}

	cout << cnt;
	return 0;
}