#include <bits/stdc++.h>
using namespace std;
int N, tmp;
priority_queue<int> pq1, pq2;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for(int i=1; i<=N; i++) {
		cin >> tmp;
		pq1.push(tmp);
	}
	for (int i = 1; i <= N; i++) {
		pq2.push(pq1.top() * i);
		pq1.pop();
	}
	cout << pq2.top();
	return 0;
}
