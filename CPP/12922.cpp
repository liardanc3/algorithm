#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> src, dst;

struct node {
	int next, capacity, revidx;
	node(int n, int c, int r) {
		next = n, capacity = c, revidx = r;
	}
}; vector<node> vect[2502];

int N, arr[52][52], visited[2502], idx[2502], level[2502], mx;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
string tmp;
void addedge(int s, int d, int undirect) {
	vect[s].push_back({ d,s == 0 ? 1'000'000'000 : 1,(int)vect[d].size() });
	vect[d].push_back({ s,0,(int)vect[s].size() - 1 });

	if (undirect) 
		addedge(d, s, 0);
}
void dfs(int y, int x, int direct, int dist) {
	int start = (y - 1) * N + x;
	if (y == dst[0].first && x == dst[0].second && direct == 0) {
		addedge(start, 2501, 0);
		return;
	}
	visited[start] = 1;

	// ¹Ù´Ú¸é 1x1
	if (!direct) {
		for(int i=0; i<4; i++){
			int ddy1 = y + dy[i];
			int ddy2 = y + 2 * dy[i];
			int ddx1 = x + dx[i];
			int ddx2 = x + 2 * dx[i];

			int end1 = (ddy1 - 1) * N + ddx1;
			int end2 = (ddy2 - 1) * N + ddx2;
			if (1 <= ddy1 && ddy1 <= N && 1 <= ddx1 && ddx1 <= N) {
				if (arr[ddy1][ddx1] || arr[ddy2][ddx2]) {

					if (arr[ddy1][ddx1]) 
						addedge(start, end1, 1);
					if (arr[ddy2][ddx2]) 
						addedge(start, end2, 1);
					
					if (!visited[end1])
						dfs(ddy1, ddx1, i + 1, 2);
					if (!visited[end2])
						dfs(ddy2, ddx2, i + 1, 1);
				}
			}
		}
	}

	// ¹Ù´Ú¸é 2x1
	else {
		int ddy = y + dist * dy[direct - 1];
		int ddx = x + dist * dx[direct - 1];

		int end = (ddy - 1) * N + ddx;
		if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N && arr[ddy][ddx]) {
			addedge(start, end, 1);
			if (!visited[end])
				dfs(ddy, ddx, 0, 1);
		}
	}

	return;
}
int bfs() {
	memset(level, -1, sizeof level);
	level[0] = 1;
	queue<int> q; q.push(0);
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

	return level[2501] == -1 ? 0 : 1;
}
int fl(int now, int wat) {
	if (now == 2501)
		return wat;

	for (int& i = idx[now]; i < vect[now].size(); i++) {
		int next = vect[now][i].next;
		int& capacity = vect[now][i].capacity;
		int& rcapacity = vect[next][vect[now][i].revidx].capacity;

		if (level[now] + 1 == level[next] && capacity > 0) {
			int blockflow = fl(next, min(wat, capacity));
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
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		for (int j = 1; j <= N; j++) {
			if (tmp[j-1] == '.')
				arr[i][j] = 1;
			else if (tmp[j-1] == 'b') {
				addedge(0, (i - 1) * N + j, 0);
				arr[i][j] = 1;
				src.push_back({ i,j });
			}
			else if (tmp[j-1] == '$') {
				arr[i][j] = 3;
				dst.push_back({ i,j });
			}
		}
	}
	for (pii p : src) {
		memset(visited, 0, sizeof(visited));
		dfs(p.first, p.second, 0, 1);
	}
	while (bfs()) {
		memset(idx, 0, sizeof(idx));
		while (1) {
			int flow = fl(0, 1e9);
			if (!flow)
				break;
			mx += flow;;
		}
	}
	cout << mx;
	return 0;
}