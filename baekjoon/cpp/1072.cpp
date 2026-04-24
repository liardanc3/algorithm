#include <bits/stdc++.h>
#define int long long
using namespace std;

int X, Y, z;
double Z;
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> X >> Y;
	
	Z = 100.0 * 1.0 * Y / (1.0 * X);
	z = floor(Z);
	int left = 1, right = 10000000000;
	int mid, ans = -1;
	while(left <= right) {
		mid = (left + right) / 2;

		Z = 100.0 * 1.0 * (Y+mid) / (1.0 * (X+mid));
		if (z != floor(Z))
			right = mid - 1, ans = mid;
		else
			left = mid + 1;
	}
	cout << ans;
	return 0;
}
