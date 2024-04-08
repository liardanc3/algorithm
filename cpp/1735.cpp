#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> a >> b >> c >> d;
	int up = a*d + c*b;
	int dn = b * d;

	cout << up / gcd(up, dn) << ' ' << dn / gcd(up, dn);

	return 0;
}
