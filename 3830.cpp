#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;

char cmd;
int n, m, a, b, c, dist[100001], tree[100001], rnk[100001];
int getRoot(int i) {
	return tree[i] == i ? i : [&]()->int {
		int root = getRoot(tree[i]);
		dist[i] += dist[tree[i]];
		return tree[i] = root;
	}();
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	while (cin >> n >> m) {
		if (!n && !m)
			break;
		for (int i = 1; i <= n; i++)
			tree[i] = i;
		memset(dist, 0, sizeof(dist));
		memset(rnk, 0, sizeof(rnk));
		while (m--) {
			cin >> cmd;
			if (cmd == '!') {
				cin >> a >> b >> c;

				if (rnk[a] < rnk[b]) {
					swap(a, b);
					c = -c;
				}

				int aroot = getRoot(a);
				int broot = getRoot(b);

				if (aroot == broot) continue;

				dist[broot] = dist[a] + c - dist[b];
				tree[broot] = aroot;

				rnk[aroot] += rnk[broot] + 1;
			}
			else {
				cin >> a >> b;
				if (getRoot(a) != getRoot(b))
					cout << "UNKNOWN\n";
				else
					cout << dist[b] - dist[a] << '\n';
			}
		}
	}
	return 0;
}