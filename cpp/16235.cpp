#include <bits/stdc++.h>
using namespace std;
int N, M, K, A[11][11], x, y, z, food[11][11], tmp[11][11], ans;
int dy[]{ -1,-1,-1,0,0,1,1,1 }, dx[]{ -1,0,1,-1,1,-1,0,1 };
vector<int> tree[11][11];
void spring() {
	memset(tmp, 0, sizeof(tmp));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].empty())
				continue;
			sort(tree[i][j].begin(), tree[i][j].end());
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k] <= food[i][j]) {
					food[i][j] -= tree[i][j][k];
					tree[i][j][k]++;
				}
				else {
					for (int s = k; s < tree[i][j].size(); s++)
						tmp[i][j] += tree[i][j][s] / 2;
					tree[i][j].erase(tree[i][j].begin() + k, tree[i][j].end());
					break;
				}
			}
		}
	}
}
void summer() {
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
		food[i][j] += tmp[i][j];
}
void autumn() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int age : tree[i][j]) {
				if (age % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						int ddy = i + dy[k];
						int ddx = j + dx[k];

						if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N) 
							tree[ddy][ddx].push_back(1);
					}
				}
			}
		}
	}
}
void winter() {
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
		food[i][j] += A[i][j];
}
int main() {
	fill(&food[0][0], &food[10][11], 5);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
		cin >> A[i][j];
	for (int i = 1; i <= M; i++) {
		cin >> y >> x >> z;
		tree[y][x].push_back(z);
	}
	while (K--) {
		spring();
		summer();
		autumn();
		winter();
	}
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
		ans += tree[i][j].size();
	}
	cout << ans;
	return 0;
}