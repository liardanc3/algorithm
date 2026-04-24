#include <bits/stdc++.h>
using namespace std;

struct node {
	int next, capacity, revidx;
	node(int n, int c, int r) {
		next = n, capacity = c, revidx = r;
	}
}; vector<node> vect[802];

int N, P, a, b, idx[802], level[802], mx;
int bfs() {
	memset(level, -1, sizeof(level));
	level[2] = 0;
	queue<int> q;
	q.push(2);
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
	return level[5] == -1 ? 0 : 1;
}
int dfs(int now, int wat) {
	if (now == 4)
		return wat;
	for (int& i = idx[now]; i < vect[now].size(); i++) {
		int next = vect[now][i].next;
		int& capacity = vect[now][i].capacity;
		int& rcapacity = vect[next][vect[now][i].revidx].capacity;

		if (level[now] + 1 == level[next] && capacity > 0) {
			int blockflow = dfs(next, min(wat, capacity));
			if (blockflow > 0) {
				capacity -= blockflow;
				rcapacity += blockflow;
				return blockflow;
			}
		}
	}
	return 0;
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> P;
		while (P--) {
			cin >> a >> b;

			// 2a+1 -> 2b
			vect[2 * a + 1].push_back({ 2 * b,1,(int)vect[2 * b].size() });
			vect[2 * b].push_back({ 2 * a + 1,0,(int)vect[2 * a + 1].size() - 1 });
			// 2b+1 -> 2a
			vect[2 * b+1].push_back({ 2 * a ,1,(int)vect[2 * a].size() });
			vect[2 * a].push_back({ 2 * b+1,0,(int)vect[2 * b+1].size() -1 });
		}
		for (int i = 1; i <= 2; i++) {
			vect[2 * i].push_back({ 2 * i + 1, 1'000'000'000, (int)vect[2 * i + 1].size() });
			vect[2 * i + 1].push_back({ 2 * i,0,(int)vect[2 * i].size() - 1 });

			vect[2 * i + 1].push_back({ 2 * i, 1'000'000'000, (int)vect[2 * i].size() });
			vect[2 * i].push_back({ 2 * i + 1, 0, (int)vect[2 * i + 1].size() - 1 });
		}
		for (int i = 3; i <= 400; i++) {
			vect[2 * i].push_back({ 2 * i + 1, 1, (int)vect[2 * i + 1].size() });
			vect[2 * i + 1].push_back({ 2 * i,0,(int)vect[2 * i].size() - 1 });

			vect[2 * i + 1].push_back({ 2 * i,1,(int)vect[2 * i].size() });
			vect[2 * i].push_back({ 2 * i + 1, 0, (int)vect[2 * i + 1].size() - 1 });
		}
	}();
	
	while (bfs()) {
		memset(idx, 0, sizeof(idx));
		while (1) {
			int flow = dfs(2, 1e9);
			if (!flow)
				break;
			mx++;
		}
	}
	cout << mx;
	return 0;
}