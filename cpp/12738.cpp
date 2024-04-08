#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> vect;
	int n, tmp; cin >> n;
	while (n--) {
		cin >> tmp;
		if (vect.size() > 0) {
			if (vect[vect.size() - 1] < tmp)
				vect.push_back(tmp);
			else {
				int idx = lower_bound(vect.begin(), vect.end(), tmp) - vect.begin();
				vect[idx] = tmp;
			}
		}
		else vect.push_back(tmp);
	}
	cout << vect.size();
	return 0;
}