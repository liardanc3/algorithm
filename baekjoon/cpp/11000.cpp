#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, s, t;
vector<pii> vect;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> s >> t;
		vect.push_back({ s,t });
	}
	sort(vect.begin(), vect.end());
	pq.push(0);
	for (int i = 0; i < vect.size(); i++) {
		int start = vect[i].first;
		int end = vect[i].second;

		if (start < pq.top()) 
			pq.push(end);
		else {
			queue<int> tmp;
			while (!pq.empty()) {
				int before_end = pq.top();
				pq.pop();
				if (before_end <= start) {
					pq.push(end);
					while (!tmp.empty()) {
						pq.push(tmp.front());
						tmp.pop();
					}
					break;
				}
				else {
					tmp.push(before_end);
				}
			}
		}
	}
	cout << pq.size();
	return 0;
}