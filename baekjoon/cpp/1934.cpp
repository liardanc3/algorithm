#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b) {
	int aa = a, bb = b;
	while (a != b) {
		a < b ? a += aa : b += bb;
	}
	return a;
}
int main() {
	int a, b, t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << lcm(a, b) << '\n';
	}
	
	return 0;
}