#include <bits/stdc++.h>
#define int long long
#define DIV 1'000'000'007
using namespace std;

vector<int> vect;
int N, tmp, ans;

int POW(int a, int b) {
	if (b == 0)
		return 1;

	int mid = POW(a, b / 2);
	mid = (mid * mid) % DIV;

	if (b % 2)
		return (mid * a) % DIV;
	return mid;
}

signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			vect.push_back(tmp);
		}
		sort(vect.begin(), vect.end());
	}();
	ans -= (vect[0] * (POW(2, N - 1) - 1));
	for (int i = 1; i < N; i++) {
		ans -= vect[i] * (POW(2, N - i - 1) - 1);
		ans += vect[i] * (POW(2, i) - 1);
		ans %= DIV;
	}
	cout << ans;
	return 0;
}