#include <bits/stdc++.h>
using namespace std;
int n, m, tmp;
vector<int> vect;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	int gap = 2000000001;
	int l = 0;
	int r = 1;
	while (l <= r && r < n) {
		if (vect.at(r) - vect.at(l) >= m) {
			gap = min(gap, vect.at(r) - vect.at(l));
			l++;
		}
		else if (vect.at(r) - vect.at(l) < m) {
			r++;
		}
	}
	cout << gap;

	return 0;
}