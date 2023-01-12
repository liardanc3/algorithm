#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, M, p, d; cin >> N >> M;
	int set_mn = 1e9, div_mn = 1e9;
	while (M--) {
		cin >> p >> d;
		set_mn = min(set_mn, p);
		div_mn = min(div_mn, d);
	}
	int div_only = div_mn * N;
	int set_only = N / 6 * set_mn;
	if (N % 6 != 0) set_only += set_mn;
	int div_set = N / 6 * set_mn + (N % 6) * div_mn;
	cout << min(div_set, min(div_only, set_only));
	return 0;
}