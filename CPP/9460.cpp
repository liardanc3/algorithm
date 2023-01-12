#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pdd;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision(1);
	int T; cin >> T;
	while (T--) {
		vector<pdd> vect;
		int n, k;
		double x, y;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			vect.push_back({ x,y });
		}
		sort(vect.begin(), vect.end());

		double left = 0.0, right = 100'000'000.0;
		double ans;
		while ((right - left) > 0.01) {
			double mid = (left + right) / 2;
			double mn = vect[0].second;
			double mx = vect[0].second;
			int cnt = 1;
			for (int i = 1; i < vect.size(); i++) {
				mn = min(mn, vect[i].second);
				mx = max(mx, vect[i].second);

				double gap = (mx - mn) / 2;

				if (gap > mid) {
					mn = vect[i].second;
					mx = vect[i].second;
					cnt++;
				}
			}
			if (cnt > k) {
				left = mid;
			}
			else {
				right = mid;
				ans = mid;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}