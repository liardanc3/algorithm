#include <bits/stdc++.h>
using namespace std;

struct node {
	int next, capacity, revidx;
	node(int n, int c, int r) {
		next = n, capacity = c, revidx = r;
	}
}; vector<node> vect[200 + 100 + 2 + 1];

int N, K, D, level[200 + 100 + 2 + 1], Z, party, tmp, mx, idx[200 + 100 + 2 + 1];
int bfs() {
	memset(level, -1, sizeof(level));
	queue<int> q;
	q.push(1);
	level[1] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (node n : vect[now]) {
			int next = n.next;
			int capacity = n.capacity;

			if (level[next] == -1 && capacity > 0) {
				level[next] = level[now] + 1;
				q.push(next);
			}
		}
	}
	return level[party] == -1 ? 0 : 1;
}
int dfs(int now, int wat) {
	if (now == party)
		return wat;
	for (int& i = idx[now]; i < vect[now].size(); i++) {
		int next = vect[now][i].next;
		int capacity = vect[now][i].capacity;
		int revidx = vect[now][i].revidx;

		if (level[now] + 1 == level[next] && capacity > 0) {
			int blockflow = dfs(next, min(wat, capacity));
			if (blockflow > 0) {
				vect[now][i].capacity -= blockflow;
				vect[next][revidx].capacity += blockflow;
				return blockflow;
			}
		}
	}
	return 0;
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> K >> D;
		party = 1 + N + D + 1;
		for (int i = 1; i <= D; i++) {
			cin >> tmp;
			vect[1 + N + i].push_back({ party,tmp,(int)vect[party].size() });
			vect[party].push_back({ 1 + N + i,0, (int)vect[1 + N + i].size() - 1 });
		}
		for (int i = 1; i <= N; i++) {
			cin >> Z;
			while (Z--) {
				cin >> tmp;
				vect[1 + i].push_back({ 1 + N + tmp,1,(int)vect[1 + N + tmp].size() });
				vect[1 + N + tmp].push_back({ 1 + i,0,(int)vect[1 + i].size() - 1 });
			}
		}
		for (int i = 1; i <= N; i++) {
			vect[1].push_back({ 1 + i, K, (int)vect[1 + i].size() });
			vect[1 + i].push_back({ 1, 0, (int)vect[1].size() - 1 });
		}
	}();
	
	while (bfs()) {
		memset(idx, 0, sizeof(idx));
		while (1) {
			int flow = dfs(1, 1e9);
			if (!flow)
				break;
			mx += flow;
		}
	}
	cout << mx;
	return 0;
}