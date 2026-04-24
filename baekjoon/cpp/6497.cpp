#include <bits/stdc++.h>
using namespace std;
int m, n, x, y, z, total, tree[200001];
typedef tuple<int, int, int> tii;
priority_queue<tii,vector<tii>,greater<tii>> pq;
int getRoot(int i) {
	return i == tree[i] ? i : tree[i] = getRoot(tree[i]);
}
void kruskal() {
	for (int i = 0; i <= m; i++)
		tree[i] = i;
	int sum = 0, u=0;
	while (!pq.empty() && u < m - 1) {
		tii tmp = pq.top(); 
		pq.pop();
		int a = get<1>(tmp);
		int b = get<2>(tmp);
		int c = get<0>(tmp);

		if (getRoot(a) == getRoot(b)) continue;
		tree[getRoot(a)] = getRoot(b);
		sum += c;
		u++;
	}
	cout << total-sum << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> m >> n) {
		if (m == 0 && n == 0) break;
		while (n--){
			cin >> x >> y >> z;
			pq.push({ z,x,y });
			total += z;
		}
		kruskal();
		total = 0;
		while (!pq.empty())
			pq.pop();
	}
	return 0;
}