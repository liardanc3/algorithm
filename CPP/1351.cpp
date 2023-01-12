#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, p, q;
map<int, int> m;
int dynamic(int _n) {
	if (m[_n]) return m[_n];
	return m[_n] = dynamic(_n / p) + dynamic(_n / q);
}
signed main() {
	m[0] = 1;
	cin >> n >> p >> q;
	cout << dynamic(n);
	return 0;
}