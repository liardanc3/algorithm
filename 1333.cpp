#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, L, D;
	cin >> N >> L >> D;
	int music = 0, ring = true;
	for (int i = 0;; i++) {
		if (i%D!=0) continue;
		else {
			if (i % (L + 5) >= L || i>=N*(L+5)) {
				cout << i;
				return 0;
			}
		}
	}
	return 0;
}