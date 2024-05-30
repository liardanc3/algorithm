#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	priority_queue<int> PQ;
	int N, tmp; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp >= 1) PQ.push(tmp);
		else {
			if (PQ.empty()) cout << 0 << "\n";
			else {
				cout << PQ.top() << "\n";  PQ.pop();
			}
		}
	}
	return 0;
}