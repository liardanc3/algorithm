#include <bits/stdc++.h>
using namespace std;
double x, y, c, ans;
int main() {
	cin >> x >> y >> c;
	cout.fixed;
	cout.precision(5);
	
	double left = 0, right = min(x, y);

	while (left < right) {

		double mid = (left + right) / 2;

		double Lheight = sqrt(pow(x, 2) - pow(mid, 2));
		double Rheight = sqrt(pow(y, 2) - pow(mid, 2));

		// y : y' = Rheight : c
		// y' = yc/Rheight
		double yprime = y * c / Rheight;

		// x : x' = Lheight : c
		// x' = xc/Lheight
		double xprime = x * c / Lheight;

		// x' : x = Rlen : mid
		// Rlen = x'*mid/x
		double Rlen = xprime * mid / x;

		// y' : y = Llen : mid
		// Llen = y'*mid/y
		double Llen = yprime * mid / y;

		if (abs(mid - (Rlen + Llen)) <= 0.001) {
			cout << mid;
			break;
		}

		if (Rlen + Llen > mid)
			right = mid;
		else left = mid;
	}
	return 0;
}