#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> vect, tmp;
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(const pii& a, const pii& b) {
	if (a.second != b.second)
		return a.second < b.second;
	return a.first < b.first;
}

int n, a, b, d, ans, L, R, mx;
int main() {
	[&](){
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			if (a > b)
				swap(a, b);
			tmp.push_back({ a,b });
		}
		cin >> d;
		for (pii p : tmp) {
			if (abs(p.first - p.second) <= d)
				vect.push_back(p);
		}
		if (vect.empty()) {
			cout << 0;
			exit(0);
		}
		sort(vect.begin(), vect.end(), cmp);
	}();
	pq.push(vect[0].first);
	L = vect[0].first, R = vect[0].second, mx = 1;
	for (int i = 1; i < vect.size(); i++) {
		int nextL = vect[i].first;
		int nextR = vect[i].second;

		R = max(R, nextR);

		L = R - d;
		while (!pq.empty() && pq.top() < L)
			pq.pop();

		pq.push(nextL);
		mx = max(mx, (int)pq.size());
		
	}
	cout << mx;
	return 0;
}