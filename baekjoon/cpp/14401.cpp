#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef tuple<int, int, int> tii;
typedef pair<int, int> pii;

priority_queue<tii, vector<tii>, less<tii>> pq;
pii point[501];

int n, m, a, b, tree[501], y, x;
int getRoot(int i) {
	return tree[i] == i ? i : tree[i] = getRoot(tree[i]);
}

bool cross(int aa, int bb) {
	int ax = point[aa].first;
	int ay = point[aa].second;
	int bx = point[bb].first;
	int by = point[bb].second;

	int aax, aay, bbx, bby;
	if (ax < bx)
		aax = ax, aay = ay, bbx = bx, bby = by;
	else
		aax = bx, aay = by, bbx = bx, bby = by;

	// (bx-ax)/(by-ay) == (nx-ax)/(ny-ay)
	for (int i = 1; i <= n; i++) {
		if (i == aa || i == bb) continue;

		int nx = point[i].first;
		int ny = point[i].second;

		if (nx<aax || nx>bbx || ny<min(bby, aay) || ny>max(bby, aay)) continue;


		if ((nx - aax) * (bby - aay) == (ny - aay) * (bbx - aax))
			return true;
	}
	return false;
}

void kruskal() {
	int sum = 0, m = 0, N = 0;
	for (int i = 1; i <= n; i++) {
		if (tree[i] == i)
			N++;
	}
	while (!pq.empty() && m < N - 1) {
		int w = get<0>(pq.top());
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());

		pq.pop();

		if (getRoot(a) == getRoot(b)) continue;
		if (cross(a, b)) continue;

		tree[getRoot(a)] = getRoot(b);

		sum += w;
		m++;
	}
	cout << sum;
}
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		tree[i] = i;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		point[i] = { x,y };
	}
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		tree[getRoot(a)] = getRoot(b);
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (i == j) continue;

			int ay = point[i].second;
			int ax = point[i].first;
			int by = point[j].second;
			int bx = point[j].first;

			int dist = (ay - by) * (ay - by) + (ax - bx) * (ax - bx);

			pq.push({ dist,i,j });
		}
	}
}
signed main() {
	init();
	kruskal();
	return 0;
}