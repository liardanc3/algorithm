#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c;
int tree[1000001];
int getRoot(int i) {
	return i == tree[i] ? i : tree[i] = getRoot(tree[i]);
}
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		tree[i] = i;
}
int main() {
	init();
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		if (a == 0) {
			if(getRoot(b)!=getRoot(c))
				tree[getRoot(b)] = getRoot(c);
		}
		else {
			if (getRoot(b) == getRoot(c))
				cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}