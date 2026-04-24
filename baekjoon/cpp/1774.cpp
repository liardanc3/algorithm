#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, tree[1001], cnt;
ll X, Y;
typedef tuple<double, int, int> tdi;
typedef pair<ll, ll> pll;
vector<pll> vect;
priority_queue<tdi, vector<tdi>, greater<tdi>> pq;
int getRoot(int i) {
	return i == tree[i] ? i : tree[i] = getRoot(tree[i]);
}
void kruskal() {
	double total = 0.0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			pll now = vect[i];
			pll next = vect[j];
			ll x1 = vect[i].first, x2 = vect[j].first;
			ll y1 = vect[i].second, y2 = vect[j].second;
			double w = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
			pq.push(tdi(w, i + 1, j + 1));
		}
	}
	while (!pq.empty() && cnt < N - 1) {
		tdi tmp = pq.top(); pq.pop();

		double w = get<0>(tmp);
		int a = get<1>(tmp);
		int b = get<2>(tmp);

		if (getRoot(a) == getRoot(b)) continue;
		tree[getRoot(a)] = getRoot(b);
		cnt++;
		total += w;
	}
	printf("%.2f", (double)round(total * 100) / 100);
}
int main() {
	cnt = 0;
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
		tree[i] = i;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y;
		vect.push_back(pll(X, Y));
	}
	while (M--) {
		cin >> X >> Y;
		if (tree[getRoot(X)] != tree[getRoot(Y)]) {
			tree[getRoot(X)] = getRoot(Y);
			cnt++;
		}
	}
	kruskal();

	return 0;
}