#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, tmp, ans; cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp == 0) {
			pq.empty() ? ans=0 : ans = pq.top();
			cout << ans << '\n';
			if (!pq.empty()) pq.pop();
		}
		else pq.push(tmp);
	}
	return 0;
}