#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
int n;
void makePrime(int i, int len) {
	bool flag = true;
	for (int j = 2; j * j <= i; j++) {
		if (i % j == 0) {
			flag = false;
			break;
		}
		if (!flag) break;
	}
	if (flag) {
		if (len == n) cout << i << '\n';
		else {
			makePrime(10 * i + 1, len + 1);
			makePrime(10 * i + 3, len + 1);
			makePrime(10 * i + 5, len + 1);
			makePrime(10 * i + 7, len + 1);
			makePrime(10 * i + 9, len + 1);
		}
	}
}
int main() {
	cin >> n;
	makePrime(2,1), makePrime(3,1), makePrime(5,1), makePrime(7,1);
}