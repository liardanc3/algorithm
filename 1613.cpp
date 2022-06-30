#include <bits/stdc++.h>
using namespace std;

int n, k, s, a, b, path[401][401];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	while (k--) {
		cin >> a >> b;
		path[a][b] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			for (int k = 1; k <= n; k++) {
				if (path[j][i] && path[i][k])
					path[j][k] = 1;
			}
		}
	}
	cin >> s;
	while (s--) {
		cin >> a >> b;
		if (path[a][b])
			cout << -1 << '\n';
		else if (path[b][a])
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}