#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, string> pis;
int s, t;
void bfs() {
	queue<pis> q;
	if (s * s <= t) q.push({ s * s,"*" });
	if (s + s <= t) q.push({ s + s,"+" });
	q.push({ s / s,"/" });
	while (!q.empty()) {
		int now = q.front().first;
		string tmp = q.front().second;
		q.pop();
		if (now == t) {
			cout << tmp;
			return;
		}
		if (now * now <= t && now != 0 && now != 1)
			q.push({ now * now,tmp + '*' });
		if (now + now <= t && now != 0)
			q.push({ now + now,tmp + '+' });
	}
	cout << "-1";
	return;
}
signed main() {
	cin >> s >> t;
	if (s == t) cout << "0";
	else if (t == 0) cout << "-";
	else if (t == 1) cout << "/";
	else bfs();
	return 0;
}