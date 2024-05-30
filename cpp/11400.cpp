#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> arti;

vector<int> vect[100001];
int N, M, a, b, visited[100001], cnt = 1;
int dfs(int now, int parent) {
	int p = visited[now] = cnt++;
	for (int next : vect[now]) {
		if (next == parent)
			continue;
		if (!visited[next]) {
			int nextp = dfs(next, now);
			if (nextp > visited[now])
				arti.push_back({ min(now,next),max(now,next) });
			p = min(p, nextp);
		}
		else
			p = min(p, visited[next]);
	}
	return p;
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		while (M--) {
			cin >> a >> b;
			vect[a].push_back(b);
			vect[b].push_back(a);
		}
	}();
	for (int i = 1; i <= N; i++) {
		if (!visited[i])
			dfs(i, 0);
	}
	sort(arti.begin(), arti.end());
	cout << arti.size() << '\n';
	for (pii p : arti)
		cout << p.first << ' ' << p.second << '\n';
	return 0;
}