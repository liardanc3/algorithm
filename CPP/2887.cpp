#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef tuple<int, int, int> tii;
typedef pair<int, int> pii;
vector<tii> vect;
vector<pii> avect, bvect, cvect;
priority_queue<tii, vector<tii>, greater<tii>> pq;

int N, a, b, c, tree[100000], dist, M;
int getRoot(int i) {
	return tree[i] == i ? i : tree[i] = getRoot(tree[i]);
}
void MST() {
	while (!pq.empty() && M < N - 1) {
		int cost = get<0>(pq.top());
		int src = get<1>(pq.top());
		int dst = get<2>(pq.top());

		pq.pop();

		if (getRoot(src) == getRoot(dst))
			continue;

		tree[getRoot(src)] = getRoot(dst);
		dist += cost;
		M++;
	}
	cout << dist;
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> a >> b >> c;
			vect.push_back({ a,b,c });
			avect.push_back({ a,i });
			bvect.push_back({ b,i });
			cvect.push_back({ c,i });
		}
		sort(avect.begin(), avect.end());
		sort(bvect.begin(), bvect.end());
		sort(cvect.begin(), cvect.end());
		for (int i = 0; i < N - 1; i++) {
			pq.push({ abs(avect[i].first - avect[i + 1].first),avect[i].second,avect[i + 1].second });
			pq.push({ abs(avect[i].first - avect[i + 1].first),avect[i + 1].second,avect[i].second });
			pq.push({ abs(bvect[i].first - bvect[i + 1].first),bvect[i].second,bvect[i + 1].second });
			pq.push({ abs(bvect[i].first - bvect[i + 1].first),bvect[i + 1].second,bvect[i].second });
			pq.push({ abs(cvect[i].first - cvect[i + 1].first),cvect[i].second,cvect[i + 1].second });
			pq.push({ abs(cvect[i].first - cvect[i + 1].first),cvect[i + 1].second,cvect[i].second });
		}
		for (int i = 0; i < N; i++)
			tree[i] = i;
	}();
	MST();
	return 0;
}