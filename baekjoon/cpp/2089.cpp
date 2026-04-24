#include <bits/stdc++.h>
using namespace std;

string ans = "";
int N, a, b;
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	[&]() {
		cin >> N;
		if (N == 0) {
			cout << 0;
			exit(0);
		}
		if (N == 1) {
			cout << 1;
			exit(0);
		}
		while (a != 1) {
			if (N < 0 && abs(N) % 2 == 1) {
				a = abs(N - 1) / 2;
				b = 1;
			}
			else {
				a = N / -2;
				b = abs(N % -2);
			}
			N = a;
			ans += b ? "1" : "0";
		}
	}();
	reverse(ans.begin(), ans.end());
	cout << 1 << ans;
	return 0;
}