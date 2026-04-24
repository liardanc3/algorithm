#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DIV 1000000007
ll a, b;
ll POW(ll a, ll b) {
	if (b == 0)
		return 1;
	ll hf = POW(a, b / 2);
	hf = hf * hf % DIV;
	if (b % 2 == 1)
		return ((a % DIV) * hf) % DIV;
	else return hf % DIV;
}
int main() {
	int N; cin >> N;
	ll ans = 0;
	while (N--) {
		cin >> b >> a;
		// b=tmp1  a=tmp2
		ll bm = POW(b, DIV-2);
		ans += ((a % DIV) * (bm % DIV)) % DIV;
		ans %= DIV;
	}
	cout << ans;
	return 0;
}