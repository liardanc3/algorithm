#include <bits/stdc++.h>
using namespace std;

int n, tmp;
vector<int> vect;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	[&]() {
		cin >> n;
		while (n--) {
			cin >> tmp;
			vect.push_back(tmp);
		}
		sort(vect.begin(), vect.end());
	}();
	for (int k = vect.size(); k >= 0; k--) {
		int idx1 = lower_bound(vect.begin(), vect.end(), k) - vect.begin();

		if (vect.size() - idx1 >= k && (vect.size()-k==0 || vect[vect.size() - k - 1] <= k)) {
			cout << k;
			break;
		}
	}
	
	
	return 0;
}
