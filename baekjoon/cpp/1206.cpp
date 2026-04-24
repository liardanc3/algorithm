#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n; cin >> n;
	vector<ll> vect;
	double tmp;
	while (n--) {
		cin >> tmp;
		ll now = tmp * 1000;
		vect.push_back(now);
	}
	for (ll man = 1;; man++) {
		bool flag = true;
		for (int j = 0; j < vect.size(); j++) {
			ll mean = vect[j];
			bool ck = false;
			if ((mean * man)%1000==0) continue;

			for (ll k = 0; k < (mean + 1) * man; k+=1000) {
				if (k < mean * man) continue;

				if (k - mean * man < man) {
					ck = true;
					break;
				}

			}
			if (ck) continue;
			else {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << man;
			return 0;
		}
	}
	return 0;
}