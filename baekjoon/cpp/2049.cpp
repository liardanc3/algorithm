#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<double, int, int> tii;
int n, xx, yy, mxx = -10001, mny = 10001;
vector<pii> inp, ans(100001), res;
vector<tii> vect;
bool cmp(const tii A, const tii B) {
	if (get<0>(A) != get<0>(B))
		return get<0>(A) < get<0>(B);
	if (abs(get<1>(A) - mxx) != abs(get<1>(B) - mxx))
		return abs(get<1>(A) - mxx) < abs(get<1>(B) - mxx);
	return abs(get<2>(A) - mny) < abs(get<2>(B) - mny);
}
double theta(pii A, pii B) {
	double dx = 0.f + B.first - A.first;
	double dy = 0.f + B.second - A.second;
	double ax = abs(dx);
	double ay = abs(dy);
	double t;

	if (ax + ay == 0) t = 0;
	else t = dy / (ax + ay);
	
	if (dx < 0) t = 2 - t;
	else if (dy < 0) t = 4 + t;
	return t * 90;
}
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
void convex_hull() {
	for (int i = 0; i < inp.size(); i++) {
		int xx = inp[i].first, yy = inp[i].second;
		if (xx == mxx && yy == mny) continue;
		vect.push_back(tii(theta({ mxx,mny }, inp[i]),inp[i].first,inp[i].second));
	}
	unique(vect.begin(), vect.end());
	sort(vect.begin(), vect.end(), cmp);
	if (vect.size() == 0) {
		std::cout << 0;
		exit(0);
	}
	ans[0] = { mxx,mny };
	ans[1] = { get<1>(vect[0]),get<2>(vect[0]) };
	int size = 2;
	for (int i = 1; i < vect.size(); i++) {
		pii now = { get<1>(vect[i]),get<2>(vect[i]) };
		while (size >= 2 && ccw(ans[size - 2], ans[size - 1], now) <= 0) {
			size--;
		}
		ans[size++] = now;
	}
	for (int i = 0; i < size; i++)
		res.push_back(ans[i]);
}
ll dist(pii A, pii B) {
	ll dx = B.first - A.first;
	ll dy = B.second - A.second;
	return dx * dx + dy * dy;
}
void rotating_calipers() {
	int left = 10001, right = -10001;
	int left_idx = -1, right_idx = -1;
	for (int i = 0; i < res.size(); i++) {
		if (res[i].first < left) {
			left = res[i].first;
			left_idx = i;
		}
		if (res[i].first > right) {
			right = res[i].first;
			right_idx = i;
		}
	}
	int L = res.size();
	ll mx = -1e9;
	for (int i = 0; i < L; i++) {
		mx = max(mx, dist(res[left_idx],res[right_idx]));
		int Lxgap = res[(left_idx + 1) % L].first - res[left_idx].first;
		int Lygap = res[(left_idx + 1) % L].second - res[left_idx].second;
		int Rxgap = res[right_idx].first - res[(right_idx + 1) % L].first;
		int Rygap = res[right_idx].second - res[(right_idx + 1) % L].second;
		pii A = res[right_idx];
		pii B = { res[right_idx].first + Rxgap,res[right_idx].second + Rygap };
		pii C = { res[right_idx].first + Lxgap,res[right_idx].second + Lygap };
		int CCW = ccw({ 0,0 }, { Rxgap,Rygap }, { Lxgap,Lygap });
		if (CCW > 0) {
			right_idx = (right_idx + 1) % L;
		}
		else left_idx = (left_idx + 1) % L;
	}
	printf("%lld", mx);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> xx >> yy;
		inp.push_back(pii(xx, yy));
		if (yy < mny || (yy == mny && xx > mxx)) {
			mny = yy;
			mxx = xx;
		}
	}
	convex_hull();
	rotating_calipers();
	return 0;
}