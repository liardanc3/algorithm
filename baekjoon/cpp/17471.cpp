#include <bits/stdc++.h>
using namespace std;
int N, tmp, arr[11], near, visited[11], mn = 1e9, wit[11][11];
vector<int> vect[11];

bool unionCheck(int ck) {
	vector<int> red;
	for (int i = 1; i <= N; i++) {
		if (visited[i]==ck) 
			red.push_back(i);
	}
	if (red.empty()) return false;
	queue<int> q;
	q.push(red[0]);

	int _visited[11]{ 0, };
	memset(_visited, 0, sizeof(_visited));
	_visited[red[0]] = 1;
	while (!q.empty() && !red.empty()) {
		int _now = q.front(); q.pop();

		for (int i = 0; i < red.size(); i++) {
			if (_now == red[i]) {
				red.erase(red.begin() + i);
				break;
			}
		}

		for (int i = 0; i < vect[_now].size(); i++) {
			int next = vect[_now][i];

			if (visited[next]==ck && !_visited[next]) {
				_visited[next] = 1;
				q.push(next);
			}
		}
	}

	return red.empty();
}

void dfs(int now, int cnt) {
	if (cnt >= N) return;
	if (cnt != 0 && cnt != N) {
		bool f1 = unionCheck(1);
		bool f2 = unionCheck(0);
		if (f1 && f2) {
			int a = 0, b = 0;
			for (int i = 1; i <= N; i++) {
				if (!visited[i])
					a += arr[i];
				else
					b += arr[i];
			}
			mn = min(mn, abs(a - b));
		}
	}

	for (int i = now; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(i + 1, cnt + 1);
			visited[i] = 0;
		}
	}
	return;
}
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		while (tmp--) {
			cin >> near;
			wit[near][i + 1] = 1;
			wit[i + 1][near] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (wit[i][j])
				vect[i].push_back(j);
		}
	}
}
int main() {
	init();

	dfs(1, 0);
		
	if (mn == 1e9) cout << -1;
	else cout << mn;
	return 0;
}