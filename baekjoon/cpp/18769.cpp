#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> radix[5];

int T, R, C, tree[250001], w;
int getRoot(int i) {
	return tree[i] == i ? i : tree[i] = getRoot(tree[i]);
}
void kruskal() {
	int m = 0, sum = 0;
	for (int i = 1; i <= 4 && m < R * C - 1; i++) {
		for (int j = 0; j < radix[i].size() && m < R * C - 1; j++) {
			int a = radix[i][j].first;
			int b = radix[i][j].second;

			if (getRoot(a) == getRoot(b)) continue;

			tree[getRoot(a)] = getRoot(b);

			sum += i;
			m++;
			if (m == (R * C - 1)) {
				cout << sum << '\n';
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while (T--) {
		for (int i = 1; i <= 4; i++)
			radix[i].clear();
		cin >> R >> C;
		for (int i = 1; i <= R * C; i++)
			tree[i] = i;
		int cnt = 0;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C - 1 && ++cnt; j++) {
				cin >> w;
				radix[w].push_back({ cnt,cnt + 1 });
			}
			cnt++;
		}
		cnt = 0;
		for (int i = 1; i <= R - 1; i++) {
			for (int j = 1; j <= C && ++cnt; j++) {
				cin >> w;
				radix[w].push_back({ cnt,cnt + C });
			}
		}
		kruskal();
	}
	return 0;
}