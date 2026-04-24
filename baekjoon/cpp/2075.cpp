#include <bits/stdc++.h>
using namespace std;
int n, tmp;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> tmp;
		if (pq.size() < n) 
			pq.push(tmp);
		else {
			if (pq.top() < tmp) {
				pq.pop();
				pq.push(tmp);
			}
		}
	}
	cout << pq.top();

	return 0;
}