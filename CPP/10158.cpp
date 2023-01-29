#include <bits/stdc++.h>
using namespace std;

int w, h, x, y, t;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> w >> h >> x >> y >> t;
	int xx = (t % (2 * w) + x) % (2 * w);
	int yy = (t % (2 * h) + y) % (2 * h);
	if (xx > w)
		xx = 2 * w - xx;
	if (yy > h)
		yy = 2 * h - yy;
	cout << xx << ' ' << yy;
	return 0;
}
