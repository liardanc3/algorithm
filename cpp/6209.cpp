#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> vect;
	int d, n, m, tmp;
	cin >> d >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	vect.push_back(0);
	vect.push_back(d);
	sort(vect.begin(), vect.end());

	int left = 0, right = d;
	int ans = 1e9;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		int gap = 0;
		for (int i = 1; i < vect.size()-1; i++) {
			if (vect[i]-gap < mid) {
				cnt++;
			}
			else {
				gap = vect[i];
			}
		}
		if (cnt > m) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << right;

	return 0;
}