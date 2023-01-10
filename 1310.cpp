#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tuple<double, ll, ll> tii;
int N, xx, yy, mxx = -50001, mny = 50001;
vector<pii> inp, ans;
vector<tii> vect;
int ccw(pii A, pii B, pii C) {
	ll dx1 = 0LL + B.first - A.first;
	ll dy1 = 0LL + B.second - A.second;
	ll dx2 = 0LL + C.first - A.first;
	ll dy2 = 0LL + C.second - A.second;

	if (dx1 * dy2 > dy1 * dx2) return 1;
	if (dx1 * dy2 < dy1 * dx2) return -1;
	if (dx1 == 0 && dy1 == 0) return 0;
	if (dx1 * dx2 < 0 || dy1 * dy2 < 0) return -1;
	if (dx1 * dx1 + dy1 * dy1 < dx2 * dx2 + dy2 * dy2) return 1;
	return 0;
}
bool cmp(const tii A, const tii B) {
	if (get<0>(A) != get<0>(B))
		return get<0>(A) < get<0>(B);
	if (abs(get<1>(A) - mxx) != abs(get<1>(B) - mxx))
		return abs(get<1>(A) - mxx) < abs(get<1>(B) - mxx);
	return abs(get<2>(A) - mny) < abs(get<2>(B) - mny);
}
double theta(pii A, pii B) {
	double dx = B.first - A.first;
	double dy = B.second - A.second;
	double ax = abs(dx);
	double ay = abs(dy);
	double t;
	if (ax + ay == 0) t = 0.f;
	else t = dy / (ax + ay);
	if (dx < 0) t = 2 - t;
	else if (dy < 0) t = 4 + t;
	return t * 90;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> xx >> yy;
		if (yy < mny || (yy == mny && xx > mxx)) {
			mxx = xx;
			mny = yy;
		}
		inp.push_back({ xx,yy });
	}
	if (N == 1) {
		cout << xx * xx + yy * yy;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		xx = inp[i].first;
		yy = inp[i].second;
		if (xx == mxx && yy == mny) continue;
		vect.push_back({ theta({mxx,mny},inp[i]),inp[i].first,inp[i].second });
	}
	sort(vect.begin(), vect.end(), cmp);

	ans.push_back({ mxx,mny });
	ans.push_back({ get<1>(vect[0]),get<2>(vect[0]) });
	int size = 2;
	for (int i = 1; i < vect.size(); i++) {
		ans.push_back({ 0,0 });
		pii now = { get<1>(vect[i]),get<2>(vect[i]) };
		while (size >= 2 && ccw(ans[size - 2], ans[size - 1], now) <= 0) {
			size--;
		}
		ans[size++] = now;
	}
	int left_idx = -1, left = 50001;
	int right_idx = -1, right = -50001;
	for (int i = 0; i < size; i++) {
		xx = ans[i].first;
		if (xx < left) {
			left = xx;
			left_idx = i;
		}
		if (xx > right) {
			right = xx;
			right_idx = i;
		}
	}
	ll mx = 0;
	for (int i = 0; i < size; i++) {
		pii R = ans[right_idx];
		pii Rn = ans[(right_idx + 1) % size];
		pii L = ans[left_idx];
		pii Ln = ans[(left_idx + 1) % size];
	
		mx = max(mx, (R.first - L.first) * (R.first - L.first) + (R.second - L.second) * (R.second - L.second));

		int Rxgap = R.first - Rn.first;
		int Rygap = R.second - Rn.second;
		int Lxgap = Ln.first - L.first;
		int Lygap = Ln.second - L.second;

		int _ccw = ccw({ 0,0 }, { Rxgap,Rygap }, { Lxgap,Lygap });
		if (_ccw > 0)
			right_idx = (right_idx + 1) % size;
		else left_idx = (left_idx + 1) % size;
	}
	cout << mx;
	return 0;
}