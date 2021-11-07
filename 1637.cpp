#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tii;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<tii> vect;
	ll N, a, c, b, mx = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		if (mx < b) mx = b;
		vect.push_back({ a,b,c });
	}
	ll left = 1, right = mx;
	ll ans = -1, ccnt = 0;
	// 1 2 3 4 5 6 7 8 9 10
	//       4 
	// 1 2 3 4 5 6 7
	//           6     9      12   15( 6 15 3 )

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll cnt = 0;
		for (int i = 0; i < vect.size(); i++) {
			ll aa = get<0>(vect[i]);
			ll bb = get<1>(vect[i]);
			ll cc = get<2>(vect[i]);
			if (mid < aa) continue;
			if (mid <= bb) {
				cnt += 1LL * (mid - aa) / cc + 1;
			}
			else if (mid > bb) {
				cnt += (bb - aa) / cc + 1;
			}
		}

		if (cnt % 2 == 1) {
			right = mid - 1;
			ans = mid;
		}
		else {
			left = mid + 1;
		}
	}
	if (ans == -1) {
		cout << "NOTHING";
		return 0;
	}
	cout << ans << ' ';
	for (int i = 0; i < vect.size(); i++) {
		ll aa = get<0>(vect[i]);
		ll bb = get<1>(vect[i]);
		ll cc = get<2>(vect[i]);
		if (aa > ans || bb < ans) continue;
		
		// 1 3 5 (1 5 2)
		if ((ans - aa) % cc == 0)
			ccnt++;
	}
	cout << ccnt;
	return 0;
}