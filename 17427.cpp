#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll N; cin >> N;
	ll ans = 0;
	for (ll i = 1; i <= N; i++) 
		ans += i*(N / i);
	cout << ans;
	return 0;
}