#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;
typedef tuple<double, int, int> tii;

vector<pii> point, ret, ans;
vector<tii> vect;

int p, n;
double xx, yy, mny, mxx, mxy, mnx;

int ccw(pii a, pii b, pii c) {
	double dx1 = b.x - a.x;
	double dx2 = c.x - a.x;
	double dy1 = b.y - a.y;
	double dy2 = c.y - a.y;

	return dy1 * dx2 < dy2 * dx1;
}

double tanz(pii a, pii b) {
	double ax = abs(a.x - b.x);
	double ay = abs(a.y - b.y);
	double dx = b.x - a.x;
	double dy = b.y - a.y;
	double t;

	if (ax + ay == 0)
		t = 0;
	else
		t = dy / (ax + ay);

	if (dx < 0) t = 2 - t;
	if (dy < 0) t = 4 + t;

	return t * 90;
}

bool cmp(const tii& a, const tii& b) {
	double tan_a = get<0>(a);
	double tan_b = get<0>(b);

	double ax = get<1>(a);
	double ay = get<2>(a);
	double bx = get<1>(b);
	double by = get<2>(b);

	if (tan_a != tan_b)
		return tan_a < tan_b;

	double abs1 = abs(mxx - ax);
	double abs2 = abs(mxx - bx);

	if (abs1 != abs2)
		return abs1 < abs2;
	return abs(mny - ay) < abs(mny - by);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> p;
	while (p--) {
		point.clear(), ret.clear(), ans.clear(), vect.clear();
		mny = 1e9, mxx = -1e9, mxy = -1e9, mnx = 1e9;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> xx >> yy;
			point.push_back({ xx,yy });
			if (yy < mny)
				mny = yy, mxx = xx;
			else if (yy == mny && xx > mxx)
				mxx = xx;
		}
		for (int i = 0; i < n; i++) {
			int x1 = point[i].x;
			int y1 = point[i].y;

			if (x1 == mxx && y1 == mny)
				continue;
			double tan = tanz({ mxx,mny }, point[i]);

			vect.push_back({ tan,point[i].x,point[i].y });
		}
		sort(vect.begin(), vect.end(), cmp);
		
		ret.assign(n, { 0,0 });
		ret[0] = { mxx,mny };
		ret[1] = { get<1>(vect[0]), get<2>(vect[0]) };
		int size = 2;

		for (int i = 1; i < n - 1; i++) {
			pii next = { get<1>(vect[i]),get<2>(vect[i]) };

			while (size >= 2 && !ccw(ret[size - 2], ret[size - 1], next))
				size--;

			ret[size++] = next;
		}

		for (int i = 0; i < size; i++) {
			ans.push_back(ret[i]);
			
			if (mxy < ret[i].y)
				mxy = ret[i].y, mnx = ret[i].x;
			else if (mxy == ret[i].y && mnx > ret[i].x)
				mnx = ret[i].x;
		}
		reverse(ans.begin(), ans.end());
		int idx = -1;
		for (int i = 0; i < size && idx == -1; i++) {
			if (ans[i].y == mxy && ans[i].x == mnx)
				idx = i;
		}
		cout << size << '\n';
		for (int i = idx; i < size; i++)
			cout << ans[i].x << ' ' << ans[i].y << '\n';
		for (int i = 0; i < idx; i++)
			cout << ans[i].x << ' ' << ans[i].y << '\n';
	}
}