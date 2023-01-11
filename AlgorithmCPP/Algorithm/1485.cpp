#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
bool cmp(const pll& v1, const pll& v2) {
	if (v1.y != v2.y)
		return v1.y < v2.y;
	return v1.x < v2.x;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll t,xx,yy; cin >> t;
	while (t--) {
		vector<pll> v;
		for (ll i = 0; i < 4; i++) {
			cin >> xx >> yy;
			v.push_back({ xx,yy });
		}
		sort(v.begin(), v.end(), cmp);
		
		ll d1 = (v[0].x - v[1].x) * (v[0].x - v[1].x) + (v[0].y - v[1].y) * (v[0].y - v[1].y);
		ll d2 = (v[0].x - v[2].x) * (v[0].x - v[2].x) + (v[0].y - v[2].y) * (v[0].y - v[2].y);
		ll d3 = (v[1].x - v[3].x) * (v[1].x - v[3].x) + (v[1].y - v[3].y) * (v[1].y - v[3].y);
		ll d4 = (v[2].x - v[3].x) * (v[2].x - v[3].x) + (v[2].y - v[3].y) * (v[2].y - v[3].y);
		ll d5 = (v[0].x - v[3].x) * (v[0].x - v[3].x) + (v[0].y - v[3].y) * (v[0].y - v[3].y);
		ll d6 = (v[1].x - v[2].x) * (v[1].x - v[2].x) + (v[1].y - v[2].y) * (v[1].y - v[2].y);
		if (d1 == d2 && d2 == d3 && d3 == d4 && d5 == d6)
			cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}