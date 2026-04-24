#include <bits/stdc++.h>
using namespace std;

int K, dist, len, arr[1010][1010], y = 505, x = 505, mnx = 505, mxx = 505, mny = 505, mxy = 505, cy, cx, ay, ax;
set<int> xset, yset;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> K;
	xset.insert(x), yset.insert(y);
	for (int i = 0; i < 6; i++) {
		cin >> dist >> len;
		if (dist == 1) {
			x += len;
			mxx = max(mxx, x);
		}
		if (dist == 2) {
			x -= len;
			mnx = min(mnx, x);
		}
		if (dist == 3) {
			y += len;
			mxy = max(mxy, y);		
		}
		if (dist == 4) {
			y -= len;
			mny = min(mny, y);
		}
		arr[y][x] = 1;
		xset.insert(x);
		yset.insert(y);
	}
	if (!arr[mny][mnx])	ay = mny, ax = mnx;
	if (!arr[mny][mxx])	ay = mny, ax = mxx;
	if (!arr[mxy][mnx])	ay = mxy, ax = mnx;
	if (!arr[mxy][mxx])	ay = mxy, ax = mxx;

	for (int y : yset) {
		if (y != mny && y != mxy) {
			cy = y;
			break;
		}
	}
	for (int x : xset) {
		if (x != mnx && x != mxx) {
			cx = x;
			break;
		}
	}
	
	cout << K * ((mxy - mny) * (mxx - mnx) - abs(cx - ax) * abs(cy - ay));
	return 0;
}