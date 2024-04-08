#include <bits/stdc++.h>
using namespace std;
int x1, yy1, x2, y2, x3, y3;
int main() {
	cin >> x1 >> yy1 >> x2 >> y2 >> x3 >> y3;

	int dx1 = x2 - x1;
	int dy1 = y2 - yy1;
	int dx2 = x3 - x1;
	int dy2 = y3 - yy1;
	
	if (dx1 * dy2 == dx2 * dy1) cout << 0;
	else if (dx1 * dy2 > dy1 * dx2) cout << 1;
	else if (dx1 * dy2 < dy1 * dx2) cout << -1;
	else if (dx1 == 0 && dy1 == 0) cout << 0;
	else if (dx1 * dx2 < 0 || dy1 * dy2 < 0) cout << -1;
	else if ((dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2)) cout << 1;
	else cout << 0;

	return 0;
}