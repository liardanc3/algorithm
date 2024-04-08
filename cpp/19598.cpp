#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> pq;
int N, a, b, mx, room;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> a >> b;
		pq.push({ a,b });
	}

	while (!pq.empty()) {
		pii now = pq.top(); pq.pop();

		int start = now.first;
		int end = now.second;

		if (end != -1) {
			room++;
			pq.push({ end,-1 });
		}
		else 
			room--;

		mx = max(mx, room);
	}

	cout << mx;
	return 0;
}