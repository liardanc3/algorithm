#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DIV = 1e9 + 7;
ll fact[4000001];
ll POW(ll a, ll b) {
	if (b == 0) return 1;
	ll hf = POW(a, b / 2);
	hf = hf * hf % DIV;
	if (b % 2 == 0)
		return hf % DIV;
	else return (a * hf) % DIV;
}
int main() {
	fact[0] = 1;
	for (int i = 1; i <= 4000000; i++)
		fact[i] = (i * fact[i - 1])%DIV;
	ll N, K;
	fact[0] = 1; fact[1] = 1;
	cin >> N >> K;
	ll up = fact[N];
	ll down = (fact[N - K] * fact[K]) % DIV;
	cout << (up * POW(down, DIV - 2)) % DIV;
	return 0;
}