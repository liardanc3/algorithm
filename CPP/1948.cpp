#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, s, e, w, d[10001], in[10001], start, final, ck[10001];
vector<pii> vect[10001];
vector<int> vect2[10001];
map<pii, int> M;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	while (m--) {
		cin >> s >> e >> w;
		vect[s].push_back(pii(e, w));
		M.insert(pair<pii, int>(pii(s, e), w));
		vect2[e].push_back(s);
		in[e]++;
	}
	cin >> start >> final;

	queue<int> q;
	q.push(start);
	d[start] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < vect[now].size(); i++) {
			int next = vect[now].at(i).first;
			int dist = vect[now].at(i).second;

			d[next] = max(d[next], d[now] + dist);
			in[next]--;
			if (in[next] == 0)
				q.push(next);
		}
	}

	ck[final] = 1;
	queue<int> Q;
	Q.push(final);
	int cnt = 0;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();

		for (int i = 0; i < vect2[now].size(); i++) {
			int parent = vect2[now].at(i);
			if (d[parent] + M[{parent, now}] == d[now]) {
				if (ck[parent] == 0) {
					Q.push(parent);
					ck[parent] = 1;
				}
				cnt++;
			}
		}

	}
	cout << d[final] << '\n' << cnt;
	return 0;
}