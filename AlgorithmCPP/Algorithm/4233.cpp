#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p, a;
ll POW(ll a, ll b) {
	if (b == 0) return 1;
	ll hf = POW(a, b/2)%p;
	hf = hf * hf % p;
	if (b % 2 == 0)
		return hf % p;
	return ((a % p) * (hf % p)) % p;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> p >> a) {
		if (!p && !a) return 0;
		int ck = 1;
		for (int i = 2; i * i <= p; i++) {
			if (p % i == 0) {
				ck = 0; break;
			}
		}
		if (ck == 0 && POW(a, p) == a)
			cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}