#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> vect;
	int N, C, tmp;
	cin >> N >> C;
	while (N--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	// 1 3 5 7 11 100
	int left = 0, right = vect[vect.size() - 1] - vect[0], mid, cnt, ans=0;
	while (left <= right) {
		int start = 0;
		cnt = 1;
		mid = (left + right) / 2;
		for (int i = start+1; cnt < C && i<vect.size(); i++) {
			if (vect[i] - vect[start] >= mid) {
				cnt++;
				start = i;
			}
		}
		if (cnt < C) 
			right = mid - 1;
		else {
			left = mid + 1;
			ans = mid;
		}
	}
	cout << ans;

	return 0;
}