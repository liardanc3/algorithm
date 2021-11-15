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
			s.push({ now,1 });
		}
		else {
			if (s.top().first == now) {
				int cnt = s.top().second;
				s.pop();
				ans += cnt;
				if (!s.empty()) ans++;
				s.push({ now,cnt + 1 });
			}
			else if (s.top().first > now) {
				ans++;
				s.push({ now,1 });
			}
		}

	}
	cout << ans;
	return 0;
}