#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, cnt, tree[500001], tmp1, tmp2, cycle;
queue<pii> q;
int getRoot(int i) {
	return i == tree[i] ? i : tree[i] = getRoot(tree[i]);
}

void disjoint() {
	int uv = 0; cycle = 0;
	while (!q.empty() && uv <= n - 1) {
		cnt++;
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (getRoot(a) == getRoot(b)) {
			cycle = 1;
			break;
		}
		if (getRoot(a) > getRoot(b))
			tree[getRoot(a)] = getRoot(b);
		else tree[getRoot(b)] = getRoot(a);
		uv++;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cnt = 0;
	cin >> n >> m;
	for (int i = 1; i < n; i++)
		tree[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> tmp1 >> tmp2;
		q.push(pii(tmp1, tmp2));
	}
	disjoint();

	if (cycle == 0) cout << 0;
	else cout << cnt;
	return 0;
}