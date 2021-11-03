#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> vect;
	int M, N, tmp;
	cin >> M >> N;
	while (N--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());

	int left = 1, right = vect[vect.size() - 1], mid, idx, cnt, ans = 0;
	while (left <= right) {
		cnt = 0;
		mid = (left + right) / 2;
		idx = lower_bound(vect.begin(), vect.end(), mid) - vect.begin();

		while (idx < vect.size() && cnt <= M)
			cnt += vect[idx++] / mid;

		if (cnt >= M) {
			left = mid + 1;
			ans = mid;
		}

		else {
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}