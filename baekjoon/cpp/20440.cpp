#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, in, out, dp[2000001], dp2[2000001], mx = -1e9, mxidx = -1e9, mxidx2 = -1e9;
vector<pii> vect;
vector<int> s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in >> out;
		vect.push_back({ in,out });
		s.push_back(in);
		s.push_back(out);
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	for (pii p : vect) {
		int start = lower_bound(s.begin(), s.end(), p.first) - s.begin() + 1;
		int end = lower_bound(s.begin(), s.end(), p.second) - s.begin() + 1;
		dp[start]++;
		dp[end]--;
	}
	int now = 0;
	bool flag = false;
	for (int i = 1; i <= s.size(); i++) {
		dp2[i] = dp2[i - 1] + dp[i];
		if (mx < dp2[i]) {
			mx = dp2[i];
			mxidx = i;
			mxidx2 = i;
			flag = true;
			continue;
		}
		if (flag && mx == dp2[i]) {
			mxidx2 = i;
			continue;
		}
		flag = false;
	}
	cout << mx << '\n';
	cout << s[mxidx - 1] << ' ' << s[mxidx2];
	return 0;
}