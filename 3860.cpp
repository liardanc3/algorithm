#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
int W, H, G, Y, X, E, Y1, X1, Y2, X2, T;
int arr[31][31];
int d[31][31];
int ck[31][31];
int dy[]{ -1,0,0,1 };
int dx[]{ 0,-1,1,0 };
map<pii, tii> M;

void bfs() {
	priority_queue<tii,vector<tii>,greater<tii>> q;
	q.push(tii(d[1][1],1, 1));
	while (!q.empty()) {
		int dist = get<0>(q.top());
		int y = get<1>(q.top());
		int x = get<2>(q.top());
		q.pop();

		// ±Í½Å±¸¸ÛÀÎ °æ¿ì
		if (arr[y][x] == 1) {
			tii hole = M[pii(y, x)];
			int ddy = get<0>(hole);
			int ddx = get<1>(hole);
			int dis = get<2>(hole);

			if (dis + dist < d[ddy][ddx]) {
			
				ck[y][x]++;
				d[ddy][ddx] = dist + dis;
				q.push(tii(d[ddy][ddx], ddy, ddx));
				
			}
			if (d[1][1] < 0) {
				cout << "Never\n";
				return;
			}
		}

		// ±Í½Å±¸¸ÛÀÌ ¾Æ´Ñ°æ¿ì
		else {
			for (int i = 0; i < 4; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];
				if (1 <= ddy && ddy <= W && 1 <= ddx && ddx <= H) {

					if (ddy == W && ddx == H) {
						d[ddy][ddx] = min(d[ddy][ddx],dist + 1);
						//d[ddy][ddx] = dist + 1;
						continue;
					}

					if (arr[ddy][ddx] == 0 || arr[ddy][ddx]==1) {
						if (d[y][x] + 1 < d[ddy][ddx]) {
							d[ddy][ddx] = dist + 1;
							q.push(tii(d[ddy][ddx], ddy, ddx));
						}
					}

				}
				if (d[1][1] < 0) {
					cout << "Never\n";
					return;
				}
			}
		}
		
	}
	if (d[W][H] == INF) cout << "Impossible\n";
	else cout << d[W][H] << '\n';
	return;
}
int main() {
	while (cin >> W >> H) {
		memset(ck, 0, sizeof(ck));
		memset(arr, 0, sizeof(arr));
		M.clear();
		fill(&d[0][0], &d[30][31], INF);
		d[1][1] = 0;
		if (W == 0 && H == 0) break;
		cin >> G;
		while (G--) {
			cin >> Y >> X;
			arr[Y + 1][X + 1] = -1;
		}
		cin >> E;
		while (E--) {
			cin >> Y1 >> X1 >> Y2 >> X2 >> T;
			arr[Y1 + 1][X1 + 1] = 1;
			M.insert(pair<pii, tii>(pii(Y1 + 1, X1 + 1), tii(Y2 + 1, X2 + 1, T)));
		}
		bfs();
	}

	return 0;
}