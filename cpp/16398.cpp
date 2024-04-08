#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef tuple<int, int, int> tii;

int N, ans, tmp, tree[1001], n;

priority_queue<tii, vector<tii>, greater<tii>> pq;

int getRoot(int i) {
	return tree[i] = (tree[i] == i) ? i : getRoot(tree[i]);
}

void kruskal() {
	while (!pq.empty() && n<N-1) {
		int w = get<0>(pq.top());
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());
		pq.pop();

		if (getRoot(a) == getRoot(b)) continue;
		
		tree[a] = getRoot(b);

		n++;
		ans += w;
	}
	return;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		tree[i] = i;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			if (i == j) continue;
			pq.push({ tmp,i,j });
		}
	}
	kruskal();
	cout << ans;
	return 0;
}