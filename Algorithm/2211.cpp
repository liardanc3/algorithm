#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tii;
typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii>> pq;
priority_queue<tii, vector<tii>, greater<tii>> pqmst;
vector<pii> vect[1001], ret;

int N, M, a, b, c, dist[1001], ans[1001][1001], cnt[1001], m, tree[1001];
int getRoot(int i) {
	return tree[i] == i ? i : tree[i] = getRoot(tree[i]);
}
int main() {
	[&]() {
		for (int i = 1; i <= 1000; i++)
			tree[i] = i;
		fill(&dist[2], &dist[1001], 1e9);
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			vect[a].push_back({ b,c });
			vect[b].push_back({ a,c });
		}
	}();
	[&]() {
		pq.push({ 0,1 });
		while (!pq.empty()) {
			int now = get<1>(pq.top());
			int d = get<0>(pq.top());

			pq.pop();

			if (dist[now] < d)
				continue;

			for (int i = 0; i < vect[now].size(); i++) {
				int next = vect[now][i].first;
				int cost = vect[now][i].second;

				if (dist[now] + cost < dist[next]) {
					dist[next] = dist[now] + cost;
					pq.push({ dist[next],next });
					pqmst.push({ dist[next],now,next });
				}
			}
		}
	}();
	[&]() {
		while (m < N - 1) {
			tii t = pqmst.top(); pqmst.pop();
			
			int cost = get<0>(t);
			int a = get<1>(t);
			int b = get<2>(t);

			if (getRoot(a) == getRoot(b))
				continue;

			tree[getRoot(a)] = getRoot(b);

			m++;
			ret.push_back({ a,b });
		}
	}();
	cout << ret.size() << '\n';
	for (pii p : ret)
		cout << p.first << ' ' << p.second << '\n';
	return 0;
}