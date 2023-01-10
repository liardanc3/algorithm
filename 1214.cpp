#include <bits/stdc++.h>
#include <assert.h>
#define int long long
using namespace std;
int a, b, c, mn = 2e9;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
signed main() {
	cin >> a >> b >> c;
	if (b > c)
		swap(b, c);
	if (a <= b)
		cout << b;
	else if (a % b == 0 || a % c == 0 || a % (b + c) == 0)
		cout << a;
	else {
		int k = a / c + 1 * (a % c != 0);
		mn = c * k - a;
		for (int i = k - 1; i >= k-1-c && i>= 0 && mn > 0; i--) {
			int aa = a - c * i;
			int b_remain = aa % b;
			if (b_remain == 0)
				mn = 0;
			else
				mn = min(mn, b - b_remain);
		}
		cout << mn + a;
	}
	return 0;
}