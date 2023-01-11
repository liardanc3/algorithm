#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
int N, E, a, b, c, cnt;
priority_queue<tii, vector<tii>, greater<tii>> pq;
int tree[10001];
int chek[10001];
int getRoot(int i) {
	while (i != tree[i]) {
		tree[i] = getRoot(i);
	}
	return tree[i];
}

void kruskal() {
	int n = 0;
	while (!pq.empty() && n<=N-1) {
		int w = get<0>(pq.top());
		int A = get<1>(pq.top());
		int B = get<2>(pq.top());
		pq.pop();

		if (getRoot(A) == getRoot(B)) continue;
		if (getRoot(B) == B)
			tree[B] = getRoot(A);
		else tree[getRoot(B)] = A;
		cnt += w;
	}
}

void init() {
	for (int i = 1; i <= 10000; i++)
		tree[i] = i;
	cin >> N >> E;
	for (int i = 1; i <= E; i++) {
		cin >> a >> b >> c;
		pq.push(tii(c, a, b));
	}
}

int main() {
	init();
	kruskal();
	cout << cnt;
	return 0;
}