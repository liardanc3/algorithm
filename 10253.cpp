#include <bits/stdc++.h>
#define int long long
using namespace std;
int T;
double a, b;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> a >> b;
		int x1 = 0;
		while (a!=0) {
			int left = 1, right = pow(2, 31), mid;
			while (left <= right) {
				mid = (left + right) / 2;

				if (b <= a*mid) {
					right = mid - 1;
					x1 = mid;
				}

				else left = mid + 1;
			}
			//cout << "1/" << x1 << ' ';
			a = a * x1 - b;
			b = b * x1;
		}
		cout << x1 << '\n';
	}
	return 0;
}