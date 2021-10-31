#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, tree[1001], cnt = 0;
ll X, Y;
typedef tuple<ll, int, int> tdi;
typedef pair<ll, ll> pll;
vector<pll> vect;
priority_queue<tdi, vector<tdi>, greater<tdi>> pq;
map <pll , int > ck;
int getRoot(int i) {
	return i == tree[i] ? i : tree[i] = getRoot(tree[i]);
}
void kruskal() {
	double total = 0.0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (ck.find({ i + 1,j + 1 }) != ck.end()) continue;
			pll now = vect[i];
			pll next = vect[j];
			ll x1 = vect[i].first, x2 = vect[j].first;
			ll y1 = vect[i].second, y2 = vect[j].second;
			ll w = pow(x1 - x2, 2) + pow(y1 - y2, 2);
			pq.push(tdi(w, i + 1, j + 1));
		}
	}
	while (!pq.empty()) {
		tdi tmp = pq.top(); pq.pop();

		double w = sqrt(get<0>(tmp));
		int a = get<1>(tmp);
		int b = get<2>(tmp);

		if (getRoot(a) == getRoot(b)) continue;
		tree[getRoot(a)] = getRoot(b);
		cnt++;
		total += w;
	}
	printf("%.2f", (double)round(total*100)/100);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
		tree[i] = i;
	for(int i=0; i<N; i++) {
		cin >> X >> Y;
		vect.push_back(pll(X, Y));
	}
	while (M--) {
		cin >> X >> Y;
		ck.insert(pair<pll, int>({ X,Y }, 1));
		ck.insert(pair<pll, int>({ Y, X }, 1));
		tree[getRoot(X)] = getRoot(Y);
		cnt++;
	}
	kruskal();

	return 0;
}