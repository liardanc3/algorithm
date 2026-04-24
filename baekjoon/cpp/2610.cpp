#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, tree[101], dist[101][101], group[101], K, mn[101], master[101];
int getRoot(int i) {
	return tree[i] == i ? i : tree[i] = getRoot(tree[i]);
}
int main() {
	[&]() {
		fill(&mn[0], &mn[101], 1e9);
		fill(&dist[0][0], &dist[100][101], 1e9);
		for (int i = 1; i <= 100; i++)
			tree[i] = i, dist[i][i] = 0, master[i] = i;
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			dist[a][b] = 1;
			dist[b][a] = 1;
			tree[getRoot(a)] = getRoot(b);
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				for (int k = 1; k <= N; k++) {
					if (i == k || j == k) continue;
					dist[k][j] = min(dist[k][j], dist[k][i] + dist[i][j]);
				}
			}
		}

		for (int i = 1; i <= N; i++) getRoot(i);
		for (int i = N; i >= 1; i--) getRoot(i);

		for (int i = 1; i <= N; i++)
			group[getRoot(i)] = 1;
		for (int i = 1; i <= N; i++)
			K += group[i];
		cout << K << '\n';
	}();
	for (int i = 1; i <= N; i++) {
		if (group[i]) {
			vector<int> vect;
			for (int j = 1; j <= N; j++) {
				if (i == getRoot(j))
					vect.push_back(j);
			}
			for (int j = 0; j < vect.size(); j++) {
				int now = vect[j];
				int tmp = 0;
				for (int k = 0; k < vect.size(); k++) {
					if (j == k) continue;
					int next = vect[k];
					int d = dist[now][next];
					tmp = max(tmp, d);
				}
				if (mn[i] > tmp) {
					master[i] = vect[j];
					mn[i] = tmp;
				}
			}
		}
	}
	vector<int> vect;
	for (int i = 1; i <= N; i++) {
		if (group[i])
			vect.push_back(master[i]);
	}
	sort(vect.begin(), vect.end());
	for (int i : vect)
		cout << i << '\n';
	return 0;
}