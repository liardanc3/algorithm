#include <bits/stdc++.h>
using namespace std;
vector<int> vect;
int main() {
	int n, tmp; cin >> n;
	while (n--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	int cost; cin >> cost;
	sort(vect.begin(), vect.end());
	int left = 0, right = vect[vect.size() - 1], mid, total, ans;
	while (left <= right) {
		mid = (left + right) / 2;
		total = 0;
		for (int i = 0; i < vect.size(); i++) {
			if (vect[i] < mid)
				total += vect[i];
			else total += mid;
		}
		if (total < cost) {
			left = mid + 1;
			ans = vect[vect.size() - 1] < mid ? vect[vect.size() - 1] : mid;
		}
		else if (total > cost) {
			right = mid - 1;
		}
		else {
			ans = vect[vect.size() - 1] < mid ? vect[vect.size() - 1] : mid;
			break;
		}
	}
	cout << ans;
	return 0;
}