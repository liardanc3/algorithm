#include <bits/stdc++.h>
using namespace std;

int A, P, now;
map<int, int> visited;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> A >> P;

	visited[A] = 1;
	now = A;
	for (int i = 2;; i++) {
		string bef = to_string(now);
		now = 0;
		for (int i = 0; i < bef.size(); i++) 
			now += pow(bef[i] - '0', P);
		if (visited[now]) {
			cout << visited[now] - 1;
			return 0;
		}
		visited[now] = i;
	}

	return 0;
}
