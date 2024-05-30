#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b) {
	return !b ? a : lcm(b, a % b);
}
int gcd(int a, int b) {
	int aa = a, bb = b;
	while (a != b) 
		a < b ? a += aa : b += bb;
	return a;
}
int main() {
	int a, b; cin >> a >> b;
	cout << lcm(a, b) << '\n' << gcd(a, b);
	return 0;
}