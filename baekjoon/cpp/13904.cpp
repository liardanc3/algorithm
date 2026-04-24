#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(const pii& a, const pii& b) {
	if (a.first != b.first)
		return a.first < b.first;
	return a.second > b.second;
}

int N, d, w, sum;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> d >> w;
		vect.push_back({ d,w });
	}
	sort(vect.begin(), vect.end(), cmp);
	for (pii p : vect) {
		if (pq.empty() || pq.size() < p.first)
			pq.push(p.second);
		else if (pq.top() < p.second){
			pq.pop();
			pq.push(p.second);
		}
	}
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
	return 0;
}