#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, b;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> a >> b;
	int res = gcd(max(a, b), min(a, b));
	while (res--)
		cout << 1;
	return 0;
}