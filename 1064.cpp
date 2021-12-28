#include <bits/stdc++.h>
using namespace std;
double mn = 1e9, mx = -1;
int main(){
	double xa, ya, xb, yb, xc, yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	
	double dx1 = xb - xa, dx2 = xc - xa, dx3 = xc - xb;
	double dy1 = yb - ya, dy2 = yc - ya, dy3 = yc - yb;
	double ax1 = abs(dx1), ax2 = abs(dx2);
	double ay1 = abs(dy1), ay2 = abs(dy2);
	double slope1 = dy1 / (ax1 + ay1);
	double slope2 = dy2 / (ax2 + ay2);
	if (abs(slope1) == abs(slope2)) {
		cout << -1;
		return 0;
	}

	double a1 = 2 * sqrt(dx1 * dx1 + dy1 * dy1) + 2 * sqrt(dx2 * dx2 + dy2 * dy2);
	double a2 = 2 * sqrt(dx1 * dx1 + dy1 * dy1) + 2 * sqrt(dx3 * dx3 + dy3 * dy3);
	double a3 = 2 * sqrt(dx2 * dx2 + dy2 * dy2) + 2 * sqrt(dx3 * dx3 + dy3 * dy3);

	mn = min(a1, min(a2, a3));
	mx = max(a1, max(a2, a3));

	cout << fixed; 
	cout.precision(15);

	cout << mx - mn;
	return 0;
}