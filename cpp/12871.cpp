#include <bits/stdc++.h>
using namespace std;

string a, b, oa, ob;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> a >> b;
	if (a.size() >= b.size())
		swap(a, b);
	oa = a, ob = b;
	int _lcm = lcm(b.size(), a.size());
	for (int i = 0; i < _lcm / oa.size() - 1; i++)
		a += oa;
	for (int i = 0; i < _lcm / ob.size() - 1; i++)
		b += ob;
	a == b ? cout << 1 : cout << 0;
	return 0;
}
