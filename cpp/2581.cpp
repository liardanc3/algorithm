#include <bits/stdc++.h>
using namespace std;
int prime[10001]{ 0, };
void init() {
	prime[0] = 1, prime[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0)
				prime[i] = 1;
		}
	}
}
int main() {
	init();
	int m, n; cin >> m >> n;
	int sum = 0, mn = 0;
	for (int i = m; i <= n; i++) {
		if (!prime[i]) {
			sum += i;
			if (mn == 0) mn = i;
		}
	}
	if (sum == 0) cout << -1;
	else {
		cout << sum << '\n' << mn;
	}
	return 0;
}