#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;

	auto _2cnt = [&](int a) {
		int ans = 0;
		while (a) {
			a /= 2;
			ans += a;
		}
		return ans;
	};

	auto _5cnt = [&](int a) {
		int ans = 0;
		while (a) {
			a /= 5;
			ans += a;
		}
		return ans;
	};

	int n2 = _2cnt(n);
	int n5 = _5cnt(n);
	int n_m2 = _2cnt(n - m);
	int n_m5 = _5cnt(n - m);
	int m2 = _2cnt(m);
	int m5 = _5cnt(m);

	cout << min(n2 - n_m2 - m2, n5 - n_m5 - m5);

	return 0;
}