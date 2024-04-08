#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int, int> tii;
typedef pair<int, int> pii;

int N, arr[21][21], M, oil, r, c, srcy, srcx, dsty, dstx, visited[21][21];
vector<int> dst[21][21], src[21][21];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
int find_dist(int starty, int startx, int endy, int endx) {
	memset(visited, 0, sizeof(visited));
	queue<pii> q;
	q.push({ starty,startx });
	int dist = -1;
	visited[starty][startx] = 1;
	while (!q.empty()) {
		dist++;
		int sz = q.size();
		while (sz--) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (y == endy && x == endx)
				return dist;

			for (int i = 0; i < 4; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];

				if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N && !arr[ddy][ddx] && !visited[ddy][ddx]) {
					visited[ddy][ddx] = 1;
					q.push({ ddy,ddx });
				}
			}
		}
	}
	return 1e8;
}
tii find_client() {
	int dist = 1e9, idx = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for(int ix : src[i][j]) {
				int d = find_dist(r, c, i, j);
				if (d < dist) {
					idx = ix;
					dist = d;
					dsty = i, dstx = j;
				}
			}
		}
	}
	return { dist,idx,dsty,dstx };
}
int find_destination(int starty, int startx, int endy, int endx) {
	memset(visited, 0, sizeof(visited));
	queue<pii> q;
	q.push({ starty,startx });
	int useoil = -1;
	visited[starty][startx] = 1;
	while (!q.empty()) {
		useoil++;
		int sz = q.size();
		while (sz--) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (y == endy && x == endx)
				return useoil;

			for (int i = 0; i < 4; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];

				if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N && !arr[ddy][ddx] && !visited[ddy][ddx]) {
					visited[ddy][ddx] = 1;
					q.push({ ddy,ddx });
				}
			}
		}
	}
	return 1e9;
}
void init() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> oil;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
		cin >> arr[i][j];
	cin >> r >> c;
	for (int i = 1; i <= M; i++) {
		cin >> srcy >> srcx >> dsty >> dstx;
		src[srcy][srcx].push_back(i);
		dst[dsty][dstx].push_back(i);
	}
}
int main() {
	init();
	while (M--) {
		// 택시가 고객 찾음
		tii t = find_client();
		int dist = get<0>(t);
		
		// 택시 -> 고객까지 가는데 연료 모자름
		if (oil < dist) {
			cout << -1;
			return 0;
		}

		oil -= dist;
		int clientidx = get<1>(t);
		srcy = get<2>(t);
		srcx = get<3>(t);
		[clientidx](){
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					for (int cc : dst[i][j]) {
						if (cc == clientidx) {
							dsty = i, dstx = j;
							return;
						}
					}
				}
			}
		}();
		
		// 출발 -> 도착
		int useoil = find_destination(srcy, srcx, dsty, dstx);

		// 도착 실패
		if (useoil > oil) {
			cout << -1;
			return 0;
		}
		oil += useoil;
		r = dsty, c = dstx;
		for (int i = 0; i < src[srcy][srcx].size(); i++) {
			int cc = src[srcy][srcx][i];
			if (cc == clientidx) {
				src[srcy][srcx].erase(src[srcy][srcx].begin() + i);
			}
		}
		for (int i = 0; i < src[dsty][dstx].size(); i++) {
			int cc = dst[dsty][dstx][i];
			if (cc == clientidx) {
				dst[dsty][dstx].erase(dst[dsty][dstx].begin() + i);
			}
		}
	}
	cout << oil;
	return 0;
}