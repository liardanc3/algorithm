#include <bits/stdc++.h>
using namespace std;

vector<int> vect[10001], arti;
int N, M, visited[10001], a, b, cnt = 1;
int dfs(int now, int root) {
	int p = visited[now] = cnt++;

	int child = 0;
	for (int next : vect[now]) {
		if (!visited[next]) {
			child++;
			int nextp = dfs(next, 0);
			if (!root && visited[now] <= nextp) 
				arti.push_back(now);
			p = min(p, nextp);
		}
		else
			p = min(p, visited[next]);
	}

	if (root && child > 1)
		arti.push_back(now);
	
	return p;
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			vect[a].push_back(b);
			vect[b].push_back(a);
		}
	}();
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) 
			dfs(i, 1);
	}
	sort(arti.begin(), arti.end());
	arti.erase(unique(arti.begin(), arti.end()), arti.end());
	cout << arti.size() << '\n';
	for (int i : arti)
		cout << i << ' ';
	return 0;
}