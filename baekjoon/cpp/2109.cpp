#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, p, d, sum;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pii> vect;

bool cmp(const pii& a, const pii& b) {
	if (a.first != b.first)
		return a.first < b.first;
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p >> d;
		vect.push_back({ d,p });
	}
	sort(vect.begin(), vect.end(), cmp);
	for (int i = 0; i < vect.size(); i++) {
		int day = vect[i].first;
		int price = vect[i].second;

		if (pq.size() < day)
			pq.push(price);
		else if (pq.top() < price) {
			pq.pop();
			pq.push(price);
		}
	}
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
	return 0;
}