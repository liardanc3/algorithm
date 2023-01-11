#include <bits/stdc++.h>
using namespace std;

int main() {
	int cnt = 0, n; cin >> n;
	// 9 - 90 - 900
	int piv = 1, length = 1;
	while(n>0) {
		n -= piv * 9;
		cnt += piv * 9 * length;
		piv *= 10;
		length++;
	}
	cnt += n * --length;
	cout << cnt;
	return 0;
}