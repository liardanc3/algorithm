#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int D, N, len, tmp, mn[300001], last, _in = 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> D >> N;
	mn[0] = 2e9, last = D+1;
	for (int i = 1; i <= D; i++) {
		cin >> tmp;
		mn[i] = min(mn[i - 1], tmp);
	}	
	for (int i = N; i >=1; i--) {
		cin >> len;
		if (!_in || last < i) {
			cout << 0;
			exit(0);
		}
		int left = 1, right = last-1, mid = 1;
		_in = 0;
		while (1<=left && left <= right) {
			mid = (left + right) / 2;

			int ovenLen = mn[mid];

			if (len <= ovenLen) {
				left = mid + 1;
				last = mid;
				_in = 1;
			}
			else {
				right = mid - 1;
			}
		}
	}
	if (_in) cout << last;
	else cout << 0;
	return 0;
}