#include <bits/stdc++.h>
using namespace std;
int n, tmp, ans;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	cin >> n;
	while (n--) {
		cin >> tmp;
		pq.push(tmp);
	}
	while (!(pq.size() == 1)) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();

		pq.push(a + b);
		ans += a + b;
	}
	cout << ans;
	return 0;
}