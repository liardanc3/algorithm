#include <bits/stdc++.h>
#define DIV 1234567891
using namespace std;
typedef long long ll;
ll POW(ll a, ll r) {
	if (r == 0)
		return 1;
	ll half = POW(a, r / 2);
	half = (half * half) % DIV;
	if (r % 2 == 1)
		half *= a;
	return half % DIV;
}
int main() {
	int L; cin >> L;
	string tmp; cin >> tmp;
	ll ans = 0;
	for (ll i = 0; i < tmp.size(); i++) {
		ll character = tmp[i] - 96;
		ll mod = (character * POW(31, i)) % DIV;
		ans += mod;
	}
	cout << ans%DIV;
	return 0;
}