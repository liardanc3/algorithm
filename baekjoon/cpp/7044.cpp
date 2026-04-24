#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef tuple<int, int, int> tii;
priority_queue<tii, vector<tii>, less<tii>> pq;

int N, M, a, b, c, tree[1001];
int getRoot(int i) {
	return tree[i] == i ? i : tree[i] = getRoot(tree[i]);
}
void kruskal() {
	int n = 0, sum = 0;
	while (!pq.empty() && n < N - 1) {
		int w = get<0>(pq.top());
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());

		pq.pop();

		if (getRoot(a) == getRoot(b)) continue;

		tree[getRoot(a)] = getRoot(b);
		sum += w;
		n++;
	}
	if (n != N - 1) cout << -1;
	else cout << sum;
	return;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		tree[i] = i;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		pq.push({ c,a,b });
	}
	kruskal();
	return 0;
}