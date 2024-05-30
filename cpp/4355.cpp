#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int n, ans;
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	while (cin >> n) {
		if (n == 0)
			break;
		if (n == 1)
			cout << 0 << '\n';
		else {
			ans = n;
			for (int i = 2; n > 1; i++) {
				if (n % i == 0) {
					ans *= (i - 1);
					ans /= i;
					while (n % i == 0)
						n /= i;
				}
			}
			cout << ans << '\n';
		}
	}

	return 0;
}
