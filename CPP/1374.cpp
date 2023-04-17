#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int N, a, b, mx, room;
int main() {
	cin >> N;
	while (N--) {
		cin >> a >> a >> b;
		pq.push({ a,b });
	}
	while (!pq.empty()) {
		pii now = pq.top(); pq.pop();

		if (now.second != -1) {
			room++;
			pq.push({ now.second, -1 });
		}
		else
			room--;

		mx = max(mx, room);
	}

	cout << mx;
	return 0;
}