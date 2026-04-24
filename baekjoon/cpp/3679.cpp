#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

typedef tuple<double, double, int> tii;
typedef tuple<double, tii> tiii;
typedef pair<double, double> pii;

vector<tii> point;
vector<tiii> vect;

int c, n;
double x, y, mny = 1e9, mxx = -1e9;
double tanz(pii a, pii b) {
	double dx = b.first - a.first;
	double dy = b.second - a.second;
	double t = (abs(dx) + abs(dy) == 0) ? 0 : dy / (abs(dy) + abs(dx));

	if (dx < 0) t = 2 - t;
	if (dy < 0) t = 4 + t;

	return t * 90;
}
bool cmp1(tiii aa, tiii bb) {
	tii a = get<1>(aa), b = get<1>(bb);
	double tanza = get<0>(aa);
	double tanzb = get<0>(bb);
	if (tanza != tanzb)
		return tanza < tanzb;
	double dist1 = (mxx - get<0>(a)) * (mxx - get<0>(a)) + (mny - get<1>(a)) * (mny - get<1>(a));
	double dist2 = (mxx - get<0>(b)) * (mxx - get<0>(b)) + (mny - get<1>(b)) * (mny - get<1>(b));
	return dist1 < dist2;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> c;
	for (int tc = 1; tc <= c; tc++) {
		cin >> n;
		point.clear();
		vect.clear();
		mny = 1e9, mxx = -1e9;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			point.push_back({ x,y,i });
			if (y < mny)
				mny = y, mxx = x;
			else if (y == mny && x > mxx)
				mxx = x;
		}
		for (int i = 0; i < n; i++) {
			pii now = { get<0>(point[i]),get<1>(point[i]) };

			double tanzent = tanz({ mxx,mny }, now);
			vect.push_back({ tanzent,point[i] });
		}
		sort(vect.begin(), vect.end(), cmp1);
		for (int i = vect.size() - 1; i > 0; i--) {
			if (get<0>(vect[i]) == get<0>(vect[i - 1]))
				continue;
			reverse(vect.begin() + i, vect.end());
			break;
		}
		for (tiii t : vect)
			cout << get<2>(get<1>(t)) << ' ';
		cout << '\n';
	}
	return 0;
}