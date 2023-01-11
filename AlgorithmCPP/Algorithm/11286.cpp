#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator()(int x, int y) {
		if (abs(x) == abs(y))
			return x > y;
		return abs(x) > abs(y);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	priority_queue<int, vector<int>, cmp> pq;
	int N, tmp; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else pq.push(tmp);
	}
	return 0;
}