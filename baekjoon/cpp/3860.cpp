#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
int W, H, G, X, Y, E, X1, Y1, X2, Y2, T, d[901], arr[30][30];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
vector<pii> vect[901];
void fun() {
	int N = W * H;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			int now = arr[i][j];
			int now_n = j * W + i;
			if (now == -1 || now == -2 || now_n == N-1) continue;
			
			for (int k = 0; k < 4; k++) {
				if (0 <= i + dx[k] && i + dx[k] < W && 0 <= j + dy[k] && j + dy[k] < H) {
					int next = arr[i + dx[k]][j + dy[k]];
					int next_n = (j + dy[k]) * W + i + dx[k];
					if (next != -1)
						vect[now_n].push_back({ next_n,1 });
				}
			}
		}
	}

	// bellmanford
	
	d[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N; j++) {
			if (d[j] == INF) continue;
			for (int k = 0; k < vect[j].size(); k++) {
				int next = vect[j][k].first;
				int dist = vect[j][k].second;

				if (d[next] > d[j] + dist) {
					d[next] = d[j] + dist;

					if (i == N) {
						d[N - 1] = -INF;
						//cout << i << " d[N-1] = -INF\n";
					}
				}
			}
		}
	}
	if (d[N - 1] == -INF) cout << "Never\n";
	else if (d[N - 1] == INF) cout << "Impossible\n";
	else cout << d[N - 1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> W >> H) {
		fill(&d[0], &d[901], INF);
		for (int i = 0; i <= 900; i++)
			vect[i].clear();
		vect->clear();
		memset(arr, 0, sizeof(arr));
		if (W == 0 && H == 0) break;
		cin >> G;
		for (int i = 0; i < G; i++) {
			cin >> X >> Y;
			arr[X][Y] = -1;
		}
		cin >> E;
		for (int i = 0; i < E; i++) {
			cin >> X1 >> Y1 >> X2 >> Y2 >> T;
			arr[X1][Y1] = -2;
			int now = Y1 * W + X1;
			int next = Y2 * W + X2;
			vect[now].push_back({ next,T });
		}
		fun();
	}
	return 0;
}