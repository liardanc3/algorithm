#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll g[1'000'001]{ 0, };
void makeg() {
	for (ll i = 1; i <= 1000000; i++) {
		for (ll j = i; j <= 1000000; j += i) 
			g[j] += i;
		g[i] += g[i - 1];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	makeg();
	ll t, n; cin >> t;
	while (t--) {
		cin >> n;
		cout << g[n] << '\n';
	}
	return 0;
}