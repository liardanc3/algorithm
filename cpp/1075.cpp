#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, F, now; cin >> N >> F;
	N /= 100;
	for (int i = 0; i <= 99; i++) {
		now = N * 100 + i;
		if (now % F == 0) {
			if (i < 10) cout << "0";
			cout << i;
			exit(0);
		}
	}
	return 0;
}