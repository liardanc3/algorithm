#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> s;
	int L, tmp, n;
	cin >> L;
	while (L--) {
		cin >> tmp;
		s.push_back(tmp);
	}
	sort(s.begin(), s.end());
	cin >> n;
	int idx = lower_bound(s.begin(), s.end(), n) - s.begin();
	if (s[idx] == n) cout << 0;
	else {
		int start = s[idx - 1] + 1, end = s[idx] - 1;
		if (start == end)
			cout << 0;
		else {
			int left = n - start;
			int right = end - n;
			cout << left * right + left + right;
		}
	}
	

	return 0;
}