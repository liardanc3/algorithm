#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m, r, a, b, c;
int item[101], d[101][101];
void fl_ws() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if(d[j][i]!=INF && d[i][k]!=INF)
					d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
}
int main() {
	fill(&d[0][0], &d[100][101], INF);
	for (int i = 1; i <= 100; i++)
		d[i][i] = 0;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		cin >> item[i];
	for (int i = 1; i <= r; i++) {
		cin >> a >> b >> c;
		d[a][b] = c;
		d[b][a] = c;
	}
	fl_ws();

	int mx = 0;
	for (int i = 1; i <= n; i++) {	
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (d[i][j] <= m) {
				tmp += item[j];
			}
		}
		if (tmp > mx) mx = tmp;
	}
	cout << mx;

	return 0;
}