#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> vect;
	int N, X, tmp;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	int left = 1, right = 100000;
	int ans;
	while (left <= right) {
		int mid = (left + right) / 2;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < mid; i++)
			pq.push(0);

		for (int i = 0; i < N; i++) {
			ll now = pq.top();
			pq.pop();
			now += vect[i];
			pq.push(now);
		}

		ll result = 0;
		while (!pq.empty()) {
			result = pq.top();
			pq.pop();
		}

		if (result <= X) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}