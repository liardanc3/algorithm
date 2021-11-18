#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
vector<pii> vect;
int ccw(pii A, pii B, pii C) {
	ll Ax = A.first, Ay = A.second;
	ll Bx = B.first, By = B.second;
	ll Cx = C.first, Cy = C.second;

	ll dx1 = Bx - Ax;
	ll dy1 = By - Ay;
	ll dx2 = Cx - Ax;
	ll dy2 = Cy - Ay;

	if (dx1 * dy2 > dy1 * dx2) return 1;
	if (dx1 * dy2 < dy1 * dx2) return -1;
	if (dx1 == 0 && dy1 == 0) return 0;
	if (dx1 * dx2 < 0 || dy1 * dy2 < 0) return -1;
	if (dx1 * dx1 + dy1 * dy1 < dx2 * dx2 + dy2 * dy2) return 1;
	return 0;
}

int main() {
	ll x, y;
	for (int i = 0; i < 4; i++) {
		cin >> x >> y;
		vect.push_back({ x,y });
	}
	ll t1 = ccw(vect[0], vect[1], vect[2]) * ccw(vect[0], vect[1], vect[3]);
	ll t2 = ccw(vect[2], vect[3], vect[0]) * ccw(vect[2], vect[3], vect[1]);
	if (t1 <= 0 && t2 <= 0) cout << 1;
	else cout << 0;
	return 0;
}