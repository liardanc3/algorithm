#include <bits/stdc++.h>
using namespace std;
typedef tuple<double, int, int> tii;
typedef pair<int, int> pii;
typedef long long ll;
vector<tii> vect;
vector<pii> inp, ans(10000);
int N, x, y, mny = 40001, mxx = -40001;
int ccw(pii A, pii B, pii C) {
	ll dx1 = B.first - A.first;
	ll dy1 = B.second - A.second;
	ll dx2 = C.first - A.first;
	ll dy2 = C.second - A.second;

	if (dx1 * dy2 > dx2 * dy1) return 1;
	if (dx1 * dy2 < dx2 * dy1) return -1;
	return 0;
}
double tanz(pii A, pii B) {
	double x1 = A.first, y1 = A.second;
	double x2 = B.first, y2 = B.second;
	double ax = abs(x2 - x1), ay = abs(y2 - y1);
	double dx = x2 - x1, dy = y2 - y1;
	double t;

	if (ax + ay == 0) t = 0;
	else t = dy / (ax + ay);

	if (dx < 0) t = 2 - t;
	if (dy < 0) t = 4 + t;

	return t * 90;
}

bool cmp(const tii& t1, const tii& t2) {
	if (get<0>(t1) != get<0>(t2))
		return t1 < t2;
	int abs1 = abs(get<1>(t1) - mxx);
	int abs2 = abs(get<1>(t2) - mxx);
	if(abs1!=abs2)
	return abs1 < abs2;
	abs1 = abs(get<2>(t1) - mny);
    abs2 = abs(get<2>(t2) - mny);
	return abs1 < abs2;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		inp.push_back({ x,y });
		if (y < mny || (y==mny && x>mxx)) {
			mny = y;
			mxx = x;
		}
	}

	for (int i = 0; i < N; i++) {
		pii A = { mxx,mny };
		pii B = inp[i];
		if (B.first == mxx && B.second == mny) continue;
		vect.push_back({ tanz({0,0},{B.first - mxx,B.second - mny}),B.first,B.second });
	}
	sort(vect.begin(), vect.end(), cmp);

	ans[0] = { mxx,mny };
	ans[1] = { get<1>(vect[0]),get<2>(vect[0]) };
	int size = 2;
	for (int i = 1; i < N - 1; i++) {
		pii C = { get<1>(vect[i]),get<2>(vect[i]) };

		while (size >= 2 && ccw(ans[size - 2], ans[size - 1], C) <= 0) {
			size--;
		}
		ans[size++] = C;
	}
	if (ccw(ans[size-2],ans[size - 1], ans[0]) == 0)
		size--;
	cout << size;
	return 0;
}