#include <bits/stdc++.h>
using namespace std;
int N, M, a, b, c;
typedef tuple<int, int, int> tii;
priority_queue<tii, vector<tii>, greater<tii>> pq;
int mx = 0, cnt = 0;
int tree[100001];
int getRoot(int i) {
	return tree[i] == i ? i : tree[i] = getRoot(tree[i]);
}
void Union(int a, int b) {
	a = getRoot(a);
	b = getRoot(b);

	if (a != b)
		tree[b] = a;
}
void kruskal() {
	int n = 0;
	while (!pq.empty() && n != N - 1) {
		int w = get<0>(pq.top());
		int A = get<1>(pq.top());
		int B = get<2>(pq.top());
		pq.pop();

		if (getRoot(A) == getRoot(B)) continue;

		tree[getRoot(A)] = getRoot(B);

		if (w > mx) mx = w;
		cnt += w;
	}
}

void init() {
	for (int i = 1; i <= 100000; i++) 
		tree[i] = i;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b >> c;
		pq.push(tii(c, a, b));
	}
}

int main() {
	init();
	kruskal();
	cout << cnt - mx;
	return 0;
}