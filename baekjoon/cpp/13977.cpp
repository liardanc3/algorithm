#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DIV = 1e9 + 7;
ll N, K, fact[4000001];
ll POW(ll a, ll b) {
	if (b == 0) return 1;
	ll hf = POW(a, b / 2);
	hf = hf * hf % DIV;
	if (b % 2)
		return (a * hf) % DIV;
	return hf % DIV;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fact[0] = 1;
	for (int i = 1; i <= 4000000; i++)
		fact[i] = (i * fact[i - 1]) % DIV;
	int M; cin >> M;
	while (M--) {
		cin >> N >> K;
		ll a = fact[N];
		ll b = (fact[N - K] * fact[K]) % DIV;
		cout <<  (a * POW(b, DIV - 2)) % DIV << '\n';
	}
	return 0;
}