#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll W, H, f, c, x1, y1, x2, y2, cnt = 0;
	cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;
	x1 += f, x2 += f;
	ll right = (y2 - y1) * (x2 - x1);
	cnt += right * (c + 1);
	if (2 * f <= W) {
		if (x1 < 2 * f) {
			ll edge = min(x2, 2 * f);
			ll left = (edge - x1) * (y2 - y1);
			cnt += left * (c + 1);
		}
	}
	else {
		if (x1 < W) {
			ll edge = min(x2, W);
			ll left = (edge - x1) * (y2 - y1);
			cnt += left * (c + 1);
		}
	}
	cout << (W * H) - cnt;
	return 0;
}