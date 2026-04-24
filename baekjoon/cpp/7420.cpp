#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

typedef pair<int, int> pii;
typedef tuple<double, int, int> tii;

vector<pii> point, ans;
vector<tii> vect;

int N, L;
double x, y, mny = 1e9, mxx = -1e9, ret;
int ccw(pii a, pii b, pii c) {
	double dx1 = b.first - a.first;
	double dx2 = c.first - a.first;
	double dy1 = b.second - a.second;
	double dy2 = c.second - a.second;

	return dy1 * dx2 < dy2 * dx1;
}
double tanz(pii a, pii b) {
	double dx = b.first - a.first;
	double dy = b.second - a.second;
	double t = abs(dx) + abs(dy) == 0 ? 0 : dy / (abs(dy) + abs(dx));
	
	if (dx < 0) t = 2 - t;
	if (dy < 0) t = 4 + t;

	return t * 90;
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> L;
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			point.push_back({ x,y });
			if (y < mny)
				mny = y, mxx = x;
			else if (y == mny && x > mxx)
				mxx = x;
		}
		for (int i = 0; i < N; i++) {
			if (point[i].first == mxx && point[i].second == mny)
				continue;

			double tanzent = tanz({ mxx,mny }, point[i]);
			vect.push_back({ tanzent,point[i].first,point[i].second });
		}
		sort(vect.begin(), vect.end());
	}();
	ans.assign(N, { 0,0 });
	ans[0] = { mxx,mny };
	ans[1] = { get<1>(vect[0]),get<2>(vect[0]) };
	int size = 2;
	for (int i = 1; i < N - 1; i++) {
		pii p = { get<1>(vect[i]),get<2>(vect[i]) };
		while (size >= 2 && !ccw(ans[size - 2], ans[size - 1], p))
			size--;
		ans[size++] = p;
	}
	for (int i = 0; i < size; i++) {
		int now = i;
		int next = (i + 1) % size;
		pii a = ans[now];
		pii b = ans[next];
		ret += sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
	}
	ret += 2 * PI * L;
	cout << (int)round(ret);
	return 0;
}