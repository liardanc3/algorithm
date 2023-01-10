#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DIV = 1'000'000'007;
ll fact[1000001];
ll POW(ll a, ll b) {
	if (b == 0) return 1;
	ll hf = POW(a, b / 2);
	hf = hf * hf % DIV;
	if (b % 2 == 0) return hf % DIV;
	return (a * hf) % DIV;
}
int main() {
	ll N, R;
	cin >> N >> R;
	fact[0] = 1;
	for (int i = 1; i <= N; i++)
		fact[i] = (i * fact[i - 1]) % DIV;
	ll a = fact[N];
	ll b = (fact[R] * fact[N - R]) % DIV;
	ll ferma = ((a%DIV) * POW(b, DIV - 2)%DIV) % DIV;
	cout << ferma;
	return 0;
}