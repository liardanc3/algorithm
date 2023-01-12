#include <bits/stdc++.h>
using namespace std;
#define DIV 1000000007
typedef long long ll;

pair<ll, ll> isPrime(ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return pair<ll, ll>(0, i);
	}
	return pair<ll, ll>(1, -1);
}

ll POW(ll a, ll b, ll n) {
	if (b == 0) return 1;
	ll hf = POW(a, b / 2, n);
	hf = hf * hf % n;
	if (b % 2 == 0)
		return hf % n;
	else return (a * hf) % n;
}

ll gcd(ll a, ll b) {
	ll tmp = a % b;
	a = b;
	b = tmp;
	if (b == 0)
		return a;
	else gcd(a, b);
}

ll mul(ll n, ll m, ll M) {
	if (!m) return 0;
	if (m & 1) return (n + mul(n * 2 % M, m / 2, M)) % M;
	else return mul(n * 2 % M, m / 2, M);
}

ll pw(ll n, ll m, ll M) {
	ll ans = 1;
	while (m) {
		if (m % 2 == 1) ans = mul(ans, n, M);
		n = mul(n, n, M); m /= 2;
	}
	return ans;
}

int main() {
	for (ll i = 1000001; ; i += 2) {
		if (isPrime(i).first == 1) continue;
		for (ll j = 2; j <= 500; j++) {
			if ((500 < i && i <= 1e15 && 2 <= j && i < j && i % j == 0) == false)
				break;
			if (pw(j, i - 1, i) != 1) break;
			if (j == 500) {
				cout << "n= " << i << " m= " << j << '\n';
				pair<ll, ll> pa = isPrime(i);
				if (pa.first == 0) {
					cout << i << ' ' << pa.second << '\n';
					return 0;
				}
			}
		}
	}
	return 0;
}