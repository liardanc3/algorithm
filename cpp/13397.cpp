#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> vect;
	int N, M, tmp;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	int left = 0, right = 5000 * 10000;
	while (left <= right) {
		int cnt = 1;
		int mid = (left + right) / 2;
		int mn = vect[0], mx = vect[0];
		for (int i = 0; i < vect.size(); i++) {
			mx = max(mx, vect[i]);
			mn = min(mn, vect[i]);

			if (mx - mn >= mid) {
				cnt++;
				mn = vect[i], mx = vect[i];
			}
		}
		if (cnt <= M) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << right;
	return 0;
}