#include <bits/stdc++.h>
using namespace std;
int N, a, b, level[100001], parent[100001], idx[100001];
vector<int> vect[100001], ret, _ret, depth[100001];
void dfs(int now, int depth) {
	level[now] = depth;
	for (int next : vect[now]) {
		if (!level[next]) {
			parent[next] = now;
			dfs(next, depth + 1);
		}
	}
	return;
}
void bfs() {
	for (int i = 0; i < ret.size() - 1; i++) {
		if (level[ret[i]] == level[ret[i + 1]] || level[ret[i]] + 1 == level[ret[i + 1]])
			continue;
		else {
			cout << 0;
			return;
		}
	}
	for (int i = 0; i < ret.size(); i++) {
		int now = ret[i];
		int _depth = level[now];
		if(vect[now].size()!=1 || now==1)
			depth[_depth].push_back(now);
	}
	for (int i = 1; i < ret.size(); i++) {
		int now = ret[i];
		int _depth = level[now];

		if (depth[_depth-1].size() > idx[_depth-1] && parent[now] == depth[_depth - 1][idx[_depth - 1]])
			continue;
		else if (depth[_depth - 1].size() > idx[_depth - 1] + 1 && parent[now] == depth[_depth - 1][idx[_depth - 1] + 1])
			idx[_depth - 1]++;
		else {
			cout << 0;
			return;
		}
	}
	cout << 1;
	return;
}
int main() {
	// input
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		for (int i = 0; i < N-1; i++) {
			cin >> a >> b;
			vect[a].push_back(b);
			vect[b].push_back(a);
		}
		for (int i = 1; i <= N; i++) {
			cin >> a;
			ret.push_back(a);
		}
	}();
	dfs(1, 1);
	bfs();
	return 0;
}