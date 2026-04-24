#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B; cin >> A >> B;
	int right = 0, left = 0;
	if (A > B && B == 1) {
		cout << A-1 << ' ' << 0;
		return 0;
	}
	if (A < B && A == 1) {
		cout << 0 << ' ' << B-1;
		return 0;
	}
	while (A != 1 || B != 1) {
		if (A > B) {
			A -= B;
			left++;
		}
		else {
			B -= A;
			right++;
		}
	}
	cout << left << ' ' << right;
	return 0;
}