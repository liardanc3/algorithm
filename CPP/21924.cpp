#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef tuple<int, int, int> tii;
priority_queue<tii, vector<tii>, greater<tii>> pq;


int N, M, a, b, c, sum, tree[100001];
int getRoot(int i) {
	return tree[i] == i ? i : tree[i] = getRoot(tree[i]);
}

void kruskal() {
	int tmp = 0, m = 0;
	while (!pq.empty() && m < N - 1) {
		int w = get<0>(pq.top());
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());

		pq.pop();

		if (getRoot(a) == getRoot(b)) continue;

		tree[getRoot(a)] = getRoot(b);

		tmp += w;
		m++;
	}
	if (m != N - 1)
		cout << -1;
	else
		cout << sum - tmp;
}

signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		tree[i] = i;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b >> c;
		pq.push({ c,a,b });
		sum += c;
	}
	kruskal();
	return 0;
}