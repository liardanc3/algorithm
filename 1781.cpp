#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;
priority_queue<int, vector<int>, greater<int>> pq;
int N, a, b, ans;
bool cmp(const pii& a, const pii& b) {
	if (a.first != b.first)
		return a.first < b.first;
	return a.second > b.second;
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	while (N--) {
		cin >> a >> b;
		vect.push_back({ a,b });
	}
	sort(vect.begin(), vect.end(), cmp);
	for (int i = 0; i < vect.size(); i++) {
		int day = pq.size();
		
		int deadline = vect[i].first;
		int cup = vect[i].second;

		if (day < deadline)
			pq.push(cup);
		else if (pq.top() < cup) {
			pq.pop();
			pq.push(cup);
		}
	}
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
	return 0;
}