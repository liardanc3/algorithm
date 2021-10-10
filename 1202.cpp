#include <bits/stdc++.h>
using namespace std;
int N, K, C, tmp;
long long ans, W, V;
multiset<int> ms;
typedef pair<int, int> pii;
vector<pii> vect;
queue<pii> pq;
void solution() {
	ans = 0;
	while (!pq.empty() && !ms.empty()) {
		int v = pq.front().first;
		int w = pq.front().second;
		pq.pop();

		auto idx = ms.lower_bound(w);
		if (idx != ms.end()) {
			ms.erase(idx);
			ans += v;
		}
	}
}
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> W >> V;
		vect.push_back(pii(V, W));
	}
	for (int i = 1; i <= K; i++) {
		cin >> tmp;
		ms.insert(tmp);
	}
	sort(vect.rbegin(), vect.rend());
	for (int i = 0; i < vect.size(); i++)
		pq.push(vect[i]);
	solution();
	cout << ans;
	return 0;
}