#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> pii;
typedef tuple<double, double, double> tii;

vector<pii> point, ans;
vector<tii> vect;

double x, y, mn = 1e9, mx = 0, mny, mxx;
int n, p;
int ccw(pii a, pii b, pii c) {
	double dx1 = b.first - a.first;
	double dx2 = c.first - a.first;
	double dy1 = b.second - a.second;
	double dy2 = c.second - a.second;

	return dy1 * dx2 < dy2* dx1;
}
double tanz(pii a, pii b) {
	double dx = b.first - a.first;
	double dy = b.second - a.second;
	double t = abs(dx) + abs(dy) == 0 ? 0 : dy / (abs(dx) + abs(dy));

	if (dx < 0) t = 2 - t;
	if (dy < 0) t = 4 + t;

	return t * 90;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cout << fixed;
	cout.precision(2);
	for (int t = 1;; t++) {
		cin >> n;
		if (!n) break;
		vect.clear();
		point.clear();
		ans.clear();
		mn = 1e9, mny = 1e9, mxx = -1e9;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			point.push_back({ x,y });
			if (y < mny)
				mny = y, mxx = x;
			else if (y == mny && x > mxx)
				mxx = x;
		}
		for (int i = 0; i < n; i++) {
			if (point[i].first == mxx && point[i].second == mny)
				continue;

			double tanzent = tanz({ mxx,mny }, point[i]);
			vect.push_back({ tanzent,point[i].first,point[i].second });
		}
		sort(vect.begin(), vect.end(), [&](tii a, tii b) {
			if (get<0>(a) != get<0>(b))
				return get<0>(a) < get<0>(b);
			double abs1 = abs(mxx - get<1>(a));
			double abs2 = abs(mxx - get<1>(b));
			if (abs1 != abs2)
				return abs1 < abs2;
			return abs(mny - get<2>(a)) < abs(mny - get<2>(b));
			});

		ans.assign(n, { 0,0 });
		int size = 2;
		ans[0] = { mxx,mny };
		ans[1] = { get<1>(vect[0]),get<2>(vect[0]) };
		for (int i = 1; i < n - 1; i++) {
			pii p = { get<1>(vect[i]),get<2>(vect[i]) };

			while (size >= 2 && !ccw(ans[size - 2], ans[size - 1], p))
				size--;
			ans[size++] = p;
		}

		for (int i = 0; i < size; i++) {
			[&]() {
				pii a = ans[i];
				pii b = ans[(i + 1) % size];

				mx = 0;
				for (int j = 0; j < n; j++) {
					pii c = point[j];

					double x1 = a.first;
					double y1 = a.second;
					double x2 = b.first;
					double y2 = b.second;
					double x3 = c.first;
					double y3 = c.second;

					if (x1 < x2) {
						swap(x1, x2);
						swap(y1, y2);
					}

					if (x1 - x2 == 0) {
						double dist = abs(x1 - x3);
						mx = max(mx, dist);
					}
					else if (y1 - y2 == 0) {
						double dist = abs(y1 - y3);
						mx = max(mx, dist);
					}
					else {
						double up = abs((x2 - x1) * (y1 - y3) - (x1 - x3) * (y2 - y1));
						double dn = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

						mx = max(mx, up / dn);
					}
				}
				mn = min(mn, mx);
			}();
		}
		cout << "Case " << t << ": " << (mn + 0.005) << '\n';
	}
	return 0;
}