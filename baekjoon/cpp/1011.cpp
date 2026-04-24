#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, x, y, mn = 1e9, gap;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> x >> y;
		gap = y - x;
		if (gap == 1) cout << 1 << '\n';
		else {
			ll sum, i, mx, mxsum;
			for (i = 1; i <= gap; i++) {
				sum = i * (i + 1) / 2 + i * (i - 1) / 2;
				if (sum <= gap) {
					mxsum = sum;
					mx = i;
				}
				else break;
			}
			ll cnt = 2 * mx - 1;
			cnt += ceil(((gap - mxsum)*1.f) / (mx*1.f));
			cout << cnt << '\n';
		}
		// 0 1 2 3 (1 1 1)
		// 1 2 ( 1 )
		// 1 2 3 ( 1 1 )
		// 1 2 3 4 ( 1 1 1 )
		// 1 2 3 4 5 ( 1 2 1 )
		// 1 2 3 4 5 6 ( 1 2 1 1 )
		// 1 2 3 4 5 6 7 ( 1 2 2 1 )

	}
	return 0;
}