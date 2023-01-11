#include <bits/stdc++.h>
using namespace std;
int prime[10001]{ 0, };
// 0 ¼Ò¼ö 
void makeprime() {
	prime[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				prime[i] = 1;
				break;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	makeprime();
	int t, n; cin >> t;
	while (t--) {
		cin >> n;
		int left, right;
		for (int i = 2; i <= n/2; i++) {
			if (prime[i] == 0 && prime[n - i] == 0) {
				left = i;
				right = n - i;
			}
		}
		cout << left << ' ' << right << '\n';
	}
	return 0;
}