#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
int n, x, y, ans=0, start, end;
vector<pii> vect;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		vect.push_back({ x,y });
	}
	sort(vect.begin(), vect.end());
	int start = vect[0].first;
	int end = vect[0].second;
	for (int i = 1; i < vect.size(); i++) {
		int new_start = vect[i].first;
		int new_end = vect[i].second;
		if (new_end <= end) continue;

		if (new_start <= end) {
			end = new_end;
		}
		else {
			ans += end - start;
			start = new_start;
			end = new_end;
		}
	}
	ans += end - start;
	cout << ans;
	return 0;
}