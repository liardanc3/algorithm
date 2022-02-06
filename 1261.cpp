#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef tuple<int, int, int> tii;
int n, m, arr[101][101], cost[10001];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
vector<pii> vect[10001];
string tmp;
void dijkstra() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int start = (i - 1) * m + j;
			for (int k = 2; k < 4; k++) {
				int y = i + dy[k];
				int x = j + dx[k];

				if (1 <= y && y <= n && 1 <= x && x <= m) {
					int end = (y - 1) * m + x;

					vect[start].push_back({ end, arr[y][x] });
					vect[end].push_back({ start,arr[i][j] });
				}
			}
		}
	}

	fill(&cost[0], &cost[10001], 1e9);
	cost[1] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (cost[now] < dist) continue;

		for (int i = 0; i < vect[now].size(); i++) {
			int next = vect[now][i].first;
			int dd = vect[now][i].second;

			if (dist + dd < cost[next]) {
				cost[next] = dist + dd;
				pq.push({ dist + dd,next });
			}
				
		}
	}
	cout << cost[n*m];
}
int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		for (int j = 1; j <= m; j++)
			arr[i][j] = tmp[j - 1] - '0';
	}
	dijkstra();
	return 0;
}