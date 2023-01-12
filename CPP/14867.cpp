#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int a, b, c, d;
map<pii, int> visited;

void bfs() {
	queue<pii> q;
	q.push({ 0,0 });
	visited[{0, 0}] = 1;
	int cnt = -1;
	while (!q.empty()) {
		cnt++;
		int sz = q.size();
		while (sz--) {
			int aa = q.front().first;
			int bb = q.front().second;
			q.pop();
			if (aa == c && bb == d) {
				cout << cnt;
				return;
			}

			// Fill aa
			if (!visited[{a, bb}]) {
				q.push({ a,bb });
				visited[{a, bb}] = 1;
			}

			// Fill bb
			if (!visited[{aa, b}]) {
				q.push({ aa,b });
				visited[{aa, b}] = 1;
			}

			// Empty aa
			if (!visited[{0, bb}]) {
				q.push({ 0,bb });
				visited[{0, bb}] = 1;
			}

			// Empty bb
			if (!visited[{aa, 0}]) {
				q.push({ aa,0 });
				visited[{aa, 0}] = 1;
			}

			// Move(aa,bb)
			int gap = bb + aa;
			if (gap > b) {
				if (!visited[{aa - (b - bb), b}]) {
					q.push({ aa - (b - bb),b });
					visited[{aa - (b - bb), b}] = 1;
				}
			}
			else {
				if (!visited[{0, gap}]) {
					q.push({ 0,gap });
					visited[{0, gap}] = 1;
				}
			}

			// Move(bb,aa)
			gap = aa + bb;
			if (gap > a) {
				if (!visited[{a, bb - (a - aa) }]) {
					q.push({ a,bb - (a - aa) });
					visited[{a, bb - (a - aa)}] = 1;
				}
			}
			else {
				if (!visited[{gap, 0}]) {
					q.push({ gap,0 });
					visited[{gap, 0}] = 1;
				}
			}
		}
	}
	cout << -1;
	return;
}

int main() {
	cin >> a >> b >> c >> d;
	bfs();
	return 0;
}