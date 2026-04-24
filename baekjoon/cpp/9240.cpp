#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<double, int, int> tii;
typedef long long ll;
int c, mny = 1001, mxx = -1001;
double x, y;
vector<pii> inp, ans;
vector<tii> vect;
int ccw(pii A, pii B, pii C) {
	ll dx1 = B.first - A.first;
	ll dy1 =  B.second - A.second;
	ll dx2 =  C.first - A.first;
	ll dy2 = C.second - A.second;

	if (dx1 * dy2 > dy1 * dx2) return 1;
	if (dx1 * dy2 < dy1 * dx2) return -1;
	return 0;
}
int CCW(pii A, pii B, pii C) {
	double dx1 = 0.f + B.first - A.first;
	double dy1 = 0.f + B.second - A.second;
	double dx2 = 0.f + C.first - A.first;
	double dy2 = 0.f + C.second - A.second;

	return dx1 * dy2 - dy1 * dx2;
}
double tanz(pii A , pii B) {
	double Ax = A.first, Bx = B.first - mxx;
	double Ay = A.second, By = B.second - mny;

	double dx = Bx - Ax;
	double dy = By - Ay;
	double ax = abs(dx);
	double ay = abs(dy);

	double t;

	if (ax + ay == 0)
		t = 0;
	else
		t = dy / (ax + ay);
	if (dx < 0)
		t = 2 - t;
	else if (dy < 0)
		t = 4 + t;
	return t * 90.0;
}
bool cmp(const tii t1, const tii t2) {
	if (get<0>(t1) != get<0>(t2))
		return get<0>(t1) < get<0>(t2);
	int abs1 = abs(get<1>(t1) - mxx);
	int abs2 = abs(get<1>(t2) - mxx);
	if (abs1 != abs2)
		return abs1 < abs2;
	abs1 = abs(get<2>(t1) - mny);
	abs2 = abs(get<2>(t2) - mny);
	return abs1 < abs2;
}
ll len(pii A, pii B) {
	return 1LL * pow(A.first - B.first, 2) + 1LL * pow(A.second - B.second, 2);
}
int main() {
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> x >> y;
		inp.push_back({ x,y });
		if (y < mny || (y == mny && x > mxx)) {
			mny = y;
			mxx = x;
		}
	}
	for (int i = 0; i < c; i++) {
		if (inp[i].first == mxx && inp[i].second == mny)
			continue;
		vect.push_back({ tanz({0,0},inp[i]),inp[i].first,inp[i].second });
	}
	sort(vect.begin(), vect.end(), cmp);
	if (vect.size() == 0) {
		cout << 0;
		return 0;
	}
	ans.push_back({ mxx,mny });
	ans.push_back({ get<1>(vect[0]),get<2>(vect[0]) });
	int size = 2;

	for (int i = 2; i < vect.size(); i++) {
		pii C = { get<1>(vect[i]),get<2>(vect[i]) };
		ans.push_back({ 0,0 });
		while (size >= 2 && ccw(ans[size - 2], ans[size - 1], C) <= 0) {
			size--;
		}
		ans[size++] = C;
	}

	int min_x = 1001, max_x = -1001;
	int min_idx = 0, max_idx = 1;
	for (int i = 0; i < size; i++) {
		int xx = ans[i].first;
		int yy = ans[i].second;
		if (xx < min_x) {
			min_x = xx;
			min_idx = i;
		}
		if (xx > max_x) {
			max_x = xx;
			max_idx = i;
		}
	}
	int L = size;
	ll lenmx = 0;
	
	for (int i = 0; i < L; i++) {
		lenmx = max(lenmx, len(ans[min_idx], ans[max_idx]));

		pii r = ans[max_idx];
		pii r_1 = ans[(max_idx + 1) % L];
		pii l = ans[min_idx];
		pii l_1 = ans[(min_idx + 1) % L];

		int Lxgap = l_1.first - l.first;
		int Lygap = l_1.second - l.second;
		int Rxgap = r.first - r_1.first;
		int Rygap = r.second - r_1.second;

		int res = ccw({ 0,0 }, { Rxgap,Rygap }, { Lxgap,Lygap });

		if (res > 0) {
			max_idx = (max_idx + 1) % L;
		}
		else {
			min_idx = (min_idx + 1) % L;
		}
	}
	
	
	
	printf("%.9f", sqrt(lenmx));
	return 0;
}