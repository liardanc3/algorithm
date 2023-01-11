#include <bits/stdc++.h>
using namespace std;

int n, ans;
signed main() {
	while (cin >> n) {
		if (n == 0) break;
		ans = n;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				ans /= i;
				ans *= (i - 1);
				while (n % i == 0)
					n /= i;
			}
		}
		if (n > 1) {
			ans /= n;
			ans *= (n - 1);
		}
		cout << ans << '\n';
	}
	return 0;
}