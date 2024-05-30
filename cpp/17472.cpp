#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
int N, M, tmp, arr[11][11], ck[11][11], tree[8];
vector<vector<pii>> group;
priority_queue<tii, vector<tii>, greater<tii>> pq;
int dy[]{ -1,0,0,1 };
int dx[]{ 0,-1,1,0 };
int getRoot(int i) {
	return i == tree[i] ? i : tree[i] = getRoot(tree[i]);
}
void kruskal() {
	int cnt = 0;
	int dist = 0;
	for (int i = 0; i <= 7; i++)
		tree[i] = i;
	while (!pq.empty() && cnt < group.size() - 1) {
		int d = get<0>(pq.top());
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());
		pq.pop();

		if (getRoot(a) == getRoot(b)) continue;
		tree[getRoot(a)] = getRoot(b);
		dist += d;
		cnt++;
	}
	for (int i = 1; i < group.size(); i++) {
		if (getRoot(i) != getRoot(i+1)) {
			cout << -1;
			return;
		}
	}
	cout << dist;
}
void mapping(int a, int b) {
	vector<pii> group_tmp;
	group_tmp.push_back({ a,b });
	ck[a][b] = 1;
	queue<pii> q;
	q.push({ a,b });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ddy = y + dy[i];
			int ddx = x + dx[i];

			if (arr[ddy][ddx] == 1 && ck[ddy][ddx] == 0) {
				ck[ddy][ddx] = 1; 
				q.push({ ddy,ddx });
				group_tmp.push_back({ ddy,ddx });
			}
		}
	}
	group.push_back(group_tmp);
}
void init() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
		cin >> arr[i][j];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 1 && ck[i][j] == 0) {
				mapping(i,j);
			}
		}
	}
	for (int i = 0; i < group.size() - 1; i++) {
		vector<pii> now = group[i];
		for (int j = i + 1; j < group.size(); j++) {
			vector<pii> next = group[j];

			int d = 1e9;
			for (int s = 0; s < now.size(); s++) {
				for (int t = 0; t < next.size(); t++) {
					int sy = now[s].first;
					int sx = now[s].second;
					int ty = next[t].first;
					int tx = next[t].second;
					
					if (sy == ty && abs(sx - tx) - 1 >= 2) {
						if (sx > tx) 
							swap(sx, tx);
						for (int r = 1; r < abs(sx - tx); r++) {
							if (arr[sy][sx + r] == 1) break;
							if (r == abs(sx - tx) - 1) d = min(d, abs(sx - tx) - 1);
						}
					}
						
					if (sx == tx && abs(sy - ty) - 1 >= 2) {
						if (sy > ty)
							swap(sy, ty);
						for (int r = 1; r < abs(sy - ty); r++) {
							if (arr[sy + r][sx] == 1) break;
							if (r == abs(sy - ty) - 1) d = min(d, abs(sy - ty) - 1);
						}
					}
				}
			}
			if (d < 1e8)
				pq.push({ d,i + 1,j + 1 });
		}
	}
	kruskal();
}
int main() {
	init();
	return 0;
}