#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tii;
typedef pair<int, int> pii;
priority_queue<tii, vector<tii>, less<tii>> pq;

int N, M, s, e, tree[100001], a, b, c, dist[100001], visited[100001];
int getRoot(int i) {
	return tree[i] == i ? i : tree[i] = getRoot(tree[i]);
}

vector<pii> vect[100001];

void dijkstra() {
	priority_queue<pii, vector<pii>, less<pii>> pq;
	pq.push({ 1e9,s });
	visited[s] = 1;
	while (!pq.empty()) {
		int now = pq.top().second;
		int d = pq.top().first;

		pq.pop();

		if (dist[now] > d) continue;
		
		for (int i = 0; i < vect[now].size(); i++) {
			int next = vect[now][i].first;
			int cost = vect[now][i].second;

			if (dist[next] < min(d,cost)) {
				dist[next] = min(d,cost);
				pq.push({ dist[next],next });
			}
		}
	}
}

void kruskal() {
	int n = 0;
	while (!pq.empty() && n < N - 1) {
		int w = get<0>(pq.top());
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());

		pq.pop();

		if (getRoot(a) == getRoot(b)) continue;

		tree[getRoot(a)] == getRoot(b);
		n++;
	}
}
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> s >> e;
	//for (int i = 1; i <= N; i++)
		//tree[i] = i;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		//pq.push({ c,a,b });
		vect[a].push_back({ b,c });
		vect[b].push_back({ a,c });
	}
}
int main() {
	init();
	//kruskal();
	dijkstra();
	cout << dist[e];
	return 0;
}