#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<pll> vect;
int main() {
	ll p1, p2, p3, x1, x2, x3;
	cin >> p1 >> p2 >> p3 >> x1 >> x2 >> x3;
	vect.push_back({ p1,x1 });
	vect.push_back({ p2,x2 });
	vect.push_back({ p3,x3 });
	sort(vect.begin(), vect.end());
	p1 = get<0>(vect[0]), x1 = get<1>(vect[0]);
	p2 = get<0>(vect[1]), x2 = get<1>(vect[1]);
	p3 = get<0>(vect[2]), x3 = get<1>(vect[2]);
	ll now = 0;
	for (int i = 0; now < p1 * p2 * p3 + x1; i++) {
		now = p1 * i + x1;
		if (now % p2 == x2 && now % p3 == x3) {
			cout << now << '\n';
			return 0;
		}
	}
	cout << -1;
	return 0;
}