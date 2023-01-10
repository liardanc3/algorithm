#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef tuple<int, int, string> pis;
int n, k, visited[100001];
void bfs() {
	visited[n] = 1;
	queue<pis> q;
	q.push({ n,0,""+to_string(n) + " " });
	while (!q.empty()) {
		int x = get<0>(q.front());
		int t = get<1>(q.front());
		string s = get<2>(q.front()); 
		q.pop();
		if (x==k) {
			cout << t << '\n' << s;
			exit(0);
		}
		if (2 * x <= 100000 && !visited[2 * x]) {
			visited[2 * x] = 1;
			q.push({ 2 * x,t + 1,s + to_string(2 * x) + " " });
		}
		if (x + 1 <= 100000 && x<k && !visited[x + 1]) {
			visited[x + 1] = 1;
			q.push({ x + 1,t + 1,s + to_string(x + 1) + " " });
		}
		if (x - 1 >= 0 && !visited[x-1]) {
			visited[x - 1] = 1;
			q.push({ x - 1,t + 1,s + to_string(x - 1) + " " });
		}
	}
	assert(false);
}
int main() {
	cin >> n >> k;
	if (n >= k) {
		cout << n - k << '\n';
		for (int i = n; i >= k; i--)
			cout << i << ' ';
	}
	else
		bfs();
	return 0;
}