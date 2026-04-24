#include <bits/stdc++.h>
using namespace std;
#define DIV 1000000007 
typedef long long ll;
ll POW(ll a, ll b) {
	if (b == 0)
		return 1;
	ll hf = POW(a, b / 2);
	hf = hf * hf % DIV;
	if (b % 2 == 1)
		return ((a % DIV) * (hf % DIV)) % DIV;
	else return hf % DIV;
}
int main() {
	ll N; cin >> N;
	cout << POW(2, N - 1);
	return 0;
}