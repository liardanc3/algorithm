#include <bits/stdc++.h>
using namespace std;
#define INF 999999999
int N, K, nxt;
int d[100001];
int ck[100001];
int dx[]{ -1,1,2 };
queue<int> q;
pair<int,int> bfs() {
	if (N == K) return pair<int, int>(0, 1);
	int cnt = 0;
	int fd = 0;
	while (!q.empty() && !fd) {
		cnt++;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front(); q.pop();
			for (int j = 0; j < 3; j++) {
				if (j == 0 || j == 1)
					nxt = now + dx[j];
				else nxt = now * dx[j];
				if (nxt >= 0 && nxt <= 100000) {
					if (nxt == K)
						fd++;
					else {
						if (d[now] + 1 <= d[nxt])
							q.push(nxt);
						d[nxt] = min(d[nxt], d[now] + 1);
					}
				}
			}
		}
	}
	return pair<int, int>(cnt, fd);
}

int main() {
	cin >> N >> K;
	q.push(N);
	fill(&d[0], &d[100001], INF);
	d[N] = 0;
	pair<int, int> ans = bfs();
	cout << ans.first << '\n' << ans.second;
	return 0;
}