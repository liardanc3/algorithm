#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, m, M, T, R; cin >> N >> m >> M >> T >> R;
	int start = 0, _m = m, clc = 0;
	if (_m + T > M) cout << -1;
	else {
		while (start != N) {
			if (_m + T <= M) {
				_m += T;
				start++;
			}
			else {
				_m -= R;
				if (_m < m) _m = m;
			}
			clc++;
		}
		cout << clc;
	}
	return 0;
}