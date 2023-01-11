#include <bits/stdc++.h>
#define int long long
using namespace std;

int mn, mx, cnt, arr[1000002];
signed main() {
	cin >> mn >> mx;
	cnt = mx - mn + 1;
	[&]() {
		for (int i = 2; i * i <= mx && cnt; i++) {
			int now = i * i;
			int left = mn - mn % now;
			for (int j = left; j <= mx; j += now) {
				if (mn <= j && j <= mx) {
					if (!arr[j - mn + 1]) {
						cnt--;
						arr[j - mn + 1] = 1;
					}
				}
			}
		}
	}();
	cout << cnt;
	return 0;
}