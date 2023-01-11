#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef tuple<double, int, int> tii;

vector<pii> point, ans, ret;
vector<tii> vect;

int n;
double x, y, mny = 1e9, mnx = 1e9, pivy = 1e9, pivx = -1e9;
char c;

double tanz(pii a, pii b) {
	double dx = b.first - a.first;
	double dy = b.second - a.second;
	double ax = abs(dx), ay = abs(dy);
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
	if (get<0>(a) != get<0>(b))
		return get<0>(a) < get<0>(b);
	if(get<1>(a) != get<1>(b))
		return get<1>(a) < get<1>(b);
	return get<2>(a) < get<2>(b);
}
int ccw(pii a, pii b, pii c) {
	double dx1 = b.first - a.first;
	double dx2 = c.first - a.first;
	double dy1 = b.second - a.second;
	double dy2 = c.second - a.second;

	return dy1 * dx2 <= dy2 * dx1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> c;
		if (c == 'N')
			continue;
		point.push_back({ x,y });
		if (x < mnx)
			mnx = x, mny = y;
		else if (x == mnx && y < mny)
			mny = y;

		if (y < pivy)
			pivy = y, pivx = x;
		else if (y == pivy && x > pivx)
			pivx = x;
	}
	for (int i = 0; i < point.size(); i++) {
		pii p = point[i];

		if (p.first == pivx && p.second == pivy)
			continue;

		vect.push_back({ tanz({pivx,pivy},p),p.first,p.second });
	}
	sort(vect.begin(), vect.end(), cmp);

	ans.assign(n+1, { 0,0 });
	ans[0] = { pivx,pivy };
	ans[1] = { get<1>(vect[0]),get<2>(vect[0]) };
	int size = 2;

	for (int i = 1; i < vect.size(); i++) {
		pii p = { get<1>(vect[i]),get<2>(vect[i]) };

		while (size >= 2 && !ccw(ans[size - 2], ans[size - 1], p))
			size--;

		ans[size++] = p;
	}

	int idx = -1;
	for (int i = 0; i < size && idx == -1; i++) {
		if (ans[i].first == mnx && ans[i].second == mny)
			idx = i;
	}
	
	cout << size << '\n';
	for (int i = idx; i < size; i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	for (int i = 0; i < idx; i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	return 0;
}