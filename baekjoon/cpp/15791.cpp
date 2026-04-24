#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DIV = 1000000007;
ll fact[1000001];
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
	for (int i = 1; i <= 1000000; i++)
		fact[i] = (i * fact[i - 1])%DIV;
	ll N, M;
	cin >> N >> M;
	ll a = fact[N];
	ll b = (fact[M] * fact[N - M]) % DIV;
	ll ferma = (a * (POW(b, DIV - 2) % DIV)) % DIV;
	cout << ferma;
	return 0;
}