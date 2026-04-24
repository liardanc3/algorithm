#include <bits/stdc++.h>
#define ESP 1e-11
using namespace std;

int t;
double xx1, yy1, xx2, yy2, r1, r2;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> xx1 >> yy1 >> r1 >> xx2 >> yy2 >> r2;
		if (r2 > r1)
			swap(r1,r2), swap(xx1, xx2), swap(yy1, yy2);

		double dist = (yy1 - yy2) * (yy1 - yy2) + (xx1 - xx2) * (xx1 - xx2);

		// 동일한 원
		if (xx1 == xx2 && yy1 == yy2 && r1 == r2)
			cout << -1 << '\n';

		// 원이 1점에서 만남(외접)
		else if (dist == (r1+r2)*(r1+r2))
			cout << 1 << '\n';

		// 원이 1점에서 만남(내접)
		else if (abs(sqrt(dist) + r2 - r1) <= ESP)
			cout << 1 << '\n';

		// 원이 0점에서 만남(미포함)
		else if (dist > (r1 + r2) * (r1+r2))
			cout << 0 << '\n';

		// 원이 0점에서 만남(포함)
		else if (sqrt(dist) + r2 < r1)
			cout << 0 << '\n';

		// 원이 2점에서 만남(접함)
		else 
			cout << 2 << '\n';
	}
	return 0;
}
