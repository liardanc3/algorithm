#include <bits/stdc++.h>
using namespace std;

int N, dist[21][21], origin[21][21], sum, flag;
int main() {
	[&]() {
		cin.tie(NULL)->sync_with_stdio(false);
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> dist[i][j];
				origin[i][j] = dist[i][j];
				sum += origin[i][j];
			}
		}
	}();
	[&]() {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				for (int k = 1; k <= N; k++) {
					if (i == k || j == k) 
						continue;
					if (dist[k][i] + dist[i][j] == dist[k][j]) {
						sum -= origin[k][j];
						origin[k][j] = 0;
					}
					if (dist[k][i] + dist[i][j] < dist[k][j]) {
						cout << -1;
						return;
					}
				}
			}
		}
		cout << sum / 2;
	}();
	return 0;
}