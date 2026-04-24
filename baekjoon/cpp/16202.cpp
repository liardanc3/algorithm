#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tii;
priority_queue<tii, vector<tii>, greater<tii>> pq;
vector<tii> vect;

int N, M, K, a, b, tree[1001];
int getRoot(int i) {
	return tree[i] == i ? i : tree[i] = getRoot(tree[i]);
}

void kruskal() {
	int sum = 0;
	int m = 0;
	while (!pq.empty() && m < N - 1) {
		int w = get<0>(pq.top());
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());
		pq.pop();

		if (getRoot(a) == getRoot(b)) continue;

		tree[getRoot(a)] = getRoot(b);
		sum += w;
		m++;
	}
	if (m == N - 1)
		cout << sum << ' ';
	else cout << 0 << ' ';
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		vect.push_back({ i,a,b });
	}
	for (int i = 0; i < K; i++) {
		for (int i = 1; i <= N; i++)
			tree[i] = i;
		while (!pq.empty())
			pq.pop();
		for (tii t : vect)
			pq.push(t);
		for (int j = 0; j < i; j++)
			pq.pop();
		kruskal();
		
	}
	return 0;
}