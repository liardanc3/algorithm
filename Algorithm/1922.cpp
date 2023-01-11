#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tii;
int N,M,tmp1,tmp2,tmp3;
priority_queue<tii, vector<tii>, greater<tii>> pq;
int tree[1001];
int getRoot(int i) {
	return i == tree[i] ? tree[i] : tree[i] = getRoot(tree[i]);
}
int kruskal() {
	for (int i = 0; i <= 1000; i++)
		tree[i] = i;
	int K = 0;
	int sum = 0;
	while (!pq.empty() && K < N - 1) {
		int w = get<0>(pq.top());
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());
		pq.pop();
		if (getRoot(a) == getRoot(b)) continue;

		tree[getRoot(a)] = getRoot(b);
		K++;
		sum += w;
	}
	return sum;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		pq.push(tii(tmp3, tmp1, tmp2));
	}
	cout << kruskal();
	return 0;
}