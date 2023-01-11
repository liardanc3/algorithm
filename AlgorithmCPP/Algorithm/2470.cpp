#include <bits/stdc++.h>
using namespace std;
int n, tmp, L, R, gap = 2'000'000'999;
vector<int> vect;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	int lidx = 0, ridx = n - 1;
	while (lidx < ridx) {
		int now = vect[lidx] + vect[ridx];
		if (abs(now) < gap) {
			L = vect[lidx], R = vect[ridx];
			gap = abs(now);
		}
		if (now > 0) ridx--;
		else if (now < 0) lidx++;
		else break;
	}
	cout << L << " " << R;
	return 0;
}