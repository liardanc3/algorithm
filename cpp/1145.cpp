#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	vector<ll> vect;
	ll n, mx;
	for (int i = 0; i < 5; i++) {
		cin >> n; 
		vect.push_back(n);
	}
	sort(vect.begin(), vect.end());
	mx = vect[0] * vect[1] * vect[2] * vect[3] * vect[4];
	ll ans = 2147000000000;
	for (int i = 0; i < 5; i++) {
		ll start = vect[i];
		for (ll now = start; now <= mx; now += start) {
			int cnt = 0;
			for (int j = 0; j < 5; j++) {
				if (now % vect[j] == 0)
					cnt++;
			}
			if (cnt >= 3) {
				if (now < ans) ans = now;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}