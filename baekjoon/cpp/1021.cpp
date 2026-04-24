#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N, M, tmp, cmd;
queue<int> q;
deque<int> deq;
pii find(int n) {
	for (int i = 0; i < deq.size(); i++) {
		if (deq.at(i) == n) 
			return { i, deq.size() - i - 1 };
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	while (M--) {
		cin >> tmp;
		q.push(tmp);
	}
	for (int i = 1; i <= N; i++)
		deq.push_back(i);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		pii pos = find(now);
		cmd += min(pos.first, pos.second + 1);
		if (pos.first < pos.second + 1) {
			while (deq.at(0) != now) {
				deq.push_back(deq.at(0));
				deq.pop_front();
			}
			deq.pop_front();
		}
		else {
			while (deq.at(0) != now) {
				deq.push_front(deq.at(deq.size()-1));
				deq.pop_back();
			}
			deq.pop_front();
		}
	}
	cout << cmd;
	return 0;
}
