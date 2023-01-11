#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int fact[1001];
int factorial(int n) {
	if (fact[n] != 0) return fact[n]%10007;
	else fact[n] = (n * factorial(n - 1)) % 10007;
	return fact[n]%10007;
}

ll POW(ll a, ll b) {
	if (b == 0) return 1;
	ll hf = POW(a, b / 2);
	hf = hf * hf % 10007;
	if (b % 2 == 0) return hf % 10007;
	else return ((a % 10007) * (hf%10007)) % 10007;
}

int main() {
	fact[0] = 1;
	int N, K;
	cin >> N >> K;
	int down = (factorial(K) * factorial(N - K)) % 10007;
	cout << (factorial(N) * POW(down,10005)) % 10007;
	return 0;
}