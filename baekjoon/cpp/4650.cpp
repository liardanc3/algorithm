#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tii;
priority_queue<tii, vector<tii>, greater<tii>> pq;

int N, k, w, now, nxt, tree[28];
char tmp;

int getRoot(int i) {
	return tree[i] = (tree[i] == i) ? i : getRoot(tree[i]);
}

int kruskal() {
	int ans = 0;
	int n = 0;
	while (!pq.empty() && n < N - 1) {
		int w = get<0>(pq.top());
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());

		pq.pop();

		if (getRoot(a) == getRoot(b)) continue;

		tree[getRoot(a)] = getRoot(b);
		n++;
		ans += w;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> N) {
		for (int i = 1; i <= 27; i++)
			tree[i] = i;
		while (!pq.empty())
			pq.pop();
		if (!N) 
			break;
		for (int i = 1; i < N; i++) {
			cin >> tmp >> k;
			now = tmp - 'A' + 1;
			while (k--) {
				cin >> tmp >> w;
				nxt = tmp - 'A' + 1;
				pq.push({ w,now,nxt });
			}
		}
		cout << kruskal() << '\n';
	}
	return 0;
}