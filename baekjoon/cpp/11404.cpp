#include <bits/stdc++.h>
using namespace std;
int a, b, c, n, m, d[101][101];

void floyd_warshall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if(d[j][i]!=1e9 && d[i][k]!=1e9)
					d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == 1e9)
				cout << "0 ";
			else cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill(&d[0][0], &d[100][101], 1e9);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		d[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}
	floyd_warshall();
	return 0;
}