#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B, ans, upper[64];
ll POW(ll a, ll b) {
	if (b == 0) return 1;
	ll hf = POW(a, b / 2);
	hf = hf * hf;
	if (b % 2 == 0) return hf;
	else return hf * a;
}
int main() {
	cin >> A >> B;
	ans = 0;
	upper[0] = 1;
	for (ll i = 1; i < 64; i++)
		upper[i] = i * POW(2, i - 1) + 1;
	bitset<64> bitA(A - 1), bitB(B);
	string a = bitA.to_string(), b = bitB.to_string();
	reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
	ll beforeB = 0, beforeA = 0;
	for (int i = 0; i < 64; i++) {
		if (b[i] == '1') {
			ans += upper[i];
			if (beforeB != 0) ans += beforeB;
			beforeB += POW(2, i);
		}
		if (a[i] == '1') {
			ans -= upper[i];
			if (beforeA != 0) ans -= beforeA;
			beforeA += POW(2, i);
		}
	}
	printf("%lld", ans);
	return 0;
}