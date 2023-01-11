#include <bits/stdc++.h>
using namespace std;
int N, M, a, b, visited[101];
vector<int> L[101], R[101], vect;

int countR(int now) {
	visited[now] = 1;
	int ret = 1;
	for (int i = 0; i < R[now].size(); i++) {
		int next = R[now][i];
		if (!visited[next])
			ret += countR(next);
	}
	return ret;
}
int countL(int now) {
	visited[now] = 1;
	int ret = 1;
	for (int i = 0; i < L[now].size(); i++) {
		int next = L[now][i];
		if (!visited[next])
			ret += countL(next);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	while (M--) {
		cin >> a >> b;
		R[b].push_back(a);
		L[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		int r = countR(i);
		memset(visited, 0, sizeof(visited));
		int l = countL(i);

		cout << N - 1 - r - l + 2 << '\n';
	}
}