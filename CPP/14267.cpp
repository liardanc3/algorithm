#include <bits/stdc++.h>
using namespace std;
int n, m, tmp, good[100001], a, b;
vector<int> vect[100001];
void dfs(int now, int sum) {
	good[now] += sum;

	for (int i = 0; i < vect[now].size(); i++) {
		int next = vect[now][i];

		dfs(next, good[now]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		if (tmp != -1)
			vect[tmp].push_back(i);
	}
	while (m--) {
		cin >> a >> b;
		good[a] += b;
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		cout << good[i] << ' ';
	return 0;
}