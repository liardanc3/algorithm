#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, M, tmp, sum;
priority_queue<int, vector<int>, greater<int>> pq;
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	while (N--) {
		cin >> tmp;
		pq.push(tmp);
	}
	while (M--) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		pq.push(a + b), pq.push(a + b);
	}
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
	return 0;
}