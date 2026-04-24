#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DIV 1'000'000'007
ll f[2000001];
void fact() {
	f[1] = 1;
	for (int i = 2; i <= 2000000; i++) {
		f[i] = (f[i - 1] * i) % DIV;
	}
}
ll POW(ll a, ll b) {
	if (b == 0) return 1;
	ll hf = POW(a, b / 2);
	hf = hf * hf % DIV;
	if (b % 2 == 0) return hf % DIV;
	else return ((a % DIV) * (hf % DIV)) % DIV;
}
int main() {
	fact();
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll T, N; cin >> T;
	while (T--) {
		cin >> N;
		ll a = f[2 * N];
		ll b = (f[N + 1]*f[N])%DIV;
		ll b_1 = POW(b, DIV-2)%DIV; 
		ll ferma = (a * b_1) % DIV;
		//ll ans = (b * ferma) % DIV;
		cout << ferma << '\n';
	}
	return 0;
}