#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, now;
	cin >> n;
	stack<pii> s;
	ll ans = 0;
	while (n--) {
		cin >> now;

		while (!s.empty() && s.top().first < now) {
			ans += s.top().second;
			s.pop();
		}

		if (s.empty()) {
			s.push(pii(now, 1));
			continue;
		}
		if (s.top().first == now) {
			pii tmp = s.top();
			s.pop();
			ans += tmp.second;
			if (!s.empty()) ans++;
			tmp.second++;
			s.push(tmp);
			continue;
		}
		s.push(pii(now, 1));
		ans++;
	}
	cout << ans;
	return 0;
}