#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, x1, y1, x2, y2, cx, cy, cr, n, cnt; cin >> T;
	while (T--) {
		cnt = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		int xr = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		cin >> n;
		while (n--) {
			cin >> cx >> cy >> cr;
			cr *= cr;
			int dist1 = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy);
			int dist2 = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy);
			if (dist1 < cr && dist2 < cr)
				continue;
			if (dist1 > cr && dist2 > cr)
				continue;
			cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}