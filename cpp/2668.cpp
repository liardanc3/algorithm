#include <bits/stdc++.h>
using namespace std;
int n, arr[101], cnt = 0, ans[101], visited[101];
int dfs(int now, int start) {
	if (now == start) return 1;
	if (visited[now] == 1) return 0;
	visited[now] = 1;
	int next = arr[now];
	int ret = dfs(next, start);
	if (ret) {
		ans[now] = 1;
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		if (ans[i]) continue;
		memset(visited, 0, sizeof(visited));
		if (arr[i] == i) ans[i] = 1;
		else {
			if (dfs(arr[i], i))
				ans[i] = 1;
		}
	}
	for(int i=1; i<=n; i++){
		if (ans[i]) {
			cnt++;
		}
	}
	cout << cnt << '\n';
	for (int i = 1; i <= n; i++) {
		if (ans[i])
			cout << i << '\n';
	}
	return 0;
}