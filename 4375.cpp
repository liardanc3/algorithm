#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n;
	while (cin >> n) {
		ll now = 1;
		for (int i = 0;; i++) {
			now %= n;
			if (now % n == 0) {
				cout << i + 1 << '\n';
				break;
			}
			now = now * 10 + 1;
		}
	}
	return 0;
}