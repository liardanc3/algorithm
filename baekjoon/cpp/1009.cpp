#include <bits/stdc++.h>
#define DIV 10
using namespace std;
int POW(int a, int b) {
	if (b == 1) return a;
	int half = POW(a, b / 2);
	half = (half * half) % DIV;
	return b & 1 ? (half * a) % DIV : half % DIV;
}
int main() {
	int t, a, b; cin >> t;
	while (t--) {
		cin >> a >> b;
		int ans = POW(a, b) % DIV;
		if (ans == 0) ans = 10;
		cout << ans<< '\n';
	}
	return 0;
}