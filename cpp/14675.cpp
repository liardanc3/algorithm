#include <bits/stdc++.h>
using namespace std;
int N, a, b, q, t, k, flag, bef;
int tree_out[100001], tree_in[100001];
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	memset(tree_out, 0, sizeof(tree_out));
	memset(tree_in, 0, sizeof(tree_in));
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		tree_out[a]++;
		tree_in[b]++;
	}
}
int main() {
	init();
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> t >> k;
		switch (t) {
		case 1:
			if (tree_in[k] + tree_out[k] >= 2)
				cout << "yes\n";
			else cout << "no\n";
			break;
		case 2:
			cout << "yes\n";
			break;
		}
	}
	return 0;
}