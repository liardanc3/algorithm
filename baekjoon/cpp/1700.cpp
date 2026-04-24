#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;

priority_queue<pii> pq;

int N, K, tmp, arr[100], cnt, on[101];

int main() {
	[&]() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL), cout.tie(NULL);
		cin >> N >> K;
		for (int i = 0; i < K; i++)
			cin >> arr[i];
		for (int i = 0; i < K; i++) {
			int last = K;
			for (int j = i + 1; j < K; j++) {
				if (arr[i] == arr[j]) {
					last = j;
					break;
				}
			}
			vect.push_back({ last,arr[i] });
		}
	}();
	for (int j = 0; j < vect.size(); j++) {
		pii p = vect[j];

		int endidx = p.first;
		int now = p.second;

		if (pq.empty())
			pq.push(p);
		else if (pq.size() < N) {

			if (on[now]) {
				queue<pii> q;
				while (pq.top().second != now) {
					q.push(pq.top());
					pq.pop();
				}
				pq.pop();
				pq.push(p);
				while (!q.empty()) {
					pq.push(q.front());
					q.pop();
				}
			}
			else
				pq.push(p);
		}
		else {
			if (on[now]) {
				queue<pii> q;
				while (pq.top().second != now) {
					q.push(pq.top());
					pq.pop();
				}
				pq.pop();
				pq.push(p);
				while (!q.empty()) {
					pq.push(q.front());
					q.pop();
				}
			}
			else {
				on[pq.top().second] = 0;
				pq.pop();
				cnt++;
				pq.push(p);
			}
		}

		on[now] = 1;
	}
	cout << cnt;
	return 0;
}