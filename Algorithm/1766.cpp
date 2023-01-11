#include <bits/stdc++.h>
using namespace std;
int N, M, A, B, in[32001];
vector<int> vect[32001];
priority_queue<int, vector<int>, greater<int>> pq;
queue<int> ans;
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		vect[A].push_back(B);
		in[B]++;
	}
	for (int i = 1; i <= N; i++) {
		if (in[i] == 0)
			pq.push(i);
	}
	while (!pq.empty()) {
		int now = pq.top();
		ans.push(now);
		pq.pop();

		for (int i = 0; i < vect[now].size(); i++) {
			int next = vect[now][i];
			in[next]--;
			if (in[next] == 0) 
				pq.push(next);
		}
	}
	while (!ans.empty()) {
		cout << ans.front() << ' ';
		ans.pop();
	}
	return 0;
}