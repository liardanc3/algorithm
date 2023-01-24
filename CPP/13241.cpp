#include <bits/stdc++.h>
#define int long long
using namespace std;

int A, B;
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a * b / (gcd(a, b));
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> A >> B;
	cout << lcm(max(A,B), min(A,B));
	return 0;
}
