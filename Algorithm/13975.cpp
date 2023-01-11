#include <bits/stdc++.h>
#define int long long
using namespace std;
int T, K, tmp, sum;
priority_queue<int, vector<int>, greater<int>> pq;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		sum = 0;
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> tmp;
			pq.push(tmp);
		}
		while (pq.size() != 1) {
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			sum += a + b;
			pq.push(a + b);
		}
		pq.pop();
		cout << sum << '\n';
	}
	return 0;
}