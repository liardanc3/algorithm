#include <bits/stdc++.h>
#define INF 2e9
using namespace std;
typedef pair<int, int> pii;
int n, m, a, b, c, s, e;
int bt[1001];
int d[1001];
vector<pii> vect[1001];
void dstra() {
	d[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, s));
	while (!pq.empty()) {
		int now = pq.top().second;
		int dist = pq.top().first;
		pq.pop();
		if (d[now] < dist) continue;

		for (int i = 0; i < vect[now].size(); i++) {
			int cost = dist + vect[now].at(i).second;
			
			if (cost < d[vect[now].at(i).first]) {
				d[vect[now].at(i).first] = cost;
				bt[vect[now].at(i).first] = now;
				pq.push(pii(cost, vect[now].at(i).first));
			}
		}
	}
}

int main() {
	fill(&d[0], &d[1001], INF);
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		vect[a].push_back(pii(b, c));
	}
	cin >> s >> e;
	bt[s] = s;
	dstra();
	int cnt = 0;
	stack<int> st;
	int idx = bt[e];
	st.push(e);
	cnt++;
	while (idx != bt[idx]) {
		st.push(idx);
		idx = bt[idx];
		cnt++;
	} 
	st.push(s);
	cnt++;
	cout << d[e] << '\n' << cnt << '\n';
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
	
	
}