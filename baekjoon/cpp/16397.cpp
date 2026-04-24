#include <bits/stdc++.h>
using namespace std;

int N, T, G, visited[100000], cnt = -1;
void bfs() {
	queue<int> q;
	q.push(N);
	visited[N] = 1;
	while (!q.empty()) {
		int sz = q.size();
		cnt++;
		if (cnt > T) {
			cout << "ANG";
			return;
		}
		while (sz--) {
			int now = q.front(); q.pop();
			if (now == G) {
				cout << cnt;
				return;
			}
			int A = now + 1;
			if (A < 100000 && !visited[A]) {
				visited[A] = 1;
				q.push(A);
			}
			
			if (now == 0)
				continue;
			int B = 2 * now;
			if (B < 100000) {
				if (B >= 10000)
					B -= 10000;
				else if (B >= 1000)
					B -= 1000;
				else if (B >= 100)
					B -= 100;
				else if (B >= 10)
					B -= 10;
				else
					B -= 1;
				if (!visited[B]) {
					q.push(B);
					visited[B] = 1;
				}
			}
		}
	}
	cout << "ANG";
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> T >> G;
	bfs();
	return 0;
}