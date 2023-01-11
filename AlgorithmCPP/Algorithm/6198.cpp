#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans = 0, tmp;
stack<int> s;
signed main() {
	s.push(1e9 + 1);
	cin >> n >> tmp;
	s.push(tmp);
	for(int i=1; i<n; i++) {
		cin >> tmp;
		if (tmp >= s.top()) {
			int cnt = 0;
			int ccnt = 0;
			while (!s.empty() && s.top() <= tmp) {
				if (s.top() == tmp) {
					while (!s.empty() && s.top() == tmp) {
						s.pop();
						ccnt++;
					}
				}
				else {
					s.pop();
					cnt++;
				}
			}
			if (ccnt == 0) {
				ans += (cnt * (cnt - 1)) / 2;
				ans += (s.size() * cnt);
			}
			else if (cnt == 0 && ccnt != 0) 
				ans += s.size();
			else {
				ans += (cnt * (cnt + 1)) / 2;
				ans += (s.size() * (cnt+ccnt));
			}
			s.push(tmp);
		}
		else {
			s.push(tmp);
		}
	}
	cout << ans + (s.size() - 1) * (s.size()) / 2 - n;
	return 0;
}