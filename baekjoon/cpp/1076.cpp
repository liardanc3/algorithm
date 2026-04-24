#include <bits/stdc++.h>
using namespace std;
map<string, long long> m;
int main() {
	m["black"] = 0, m["brown"] = 1, m["red"] = 2, m["orange"] = 3,
		m["yellow"] = 4, m["green"] = 5, m["blue"] = 6, m["violet"] = 7,
		m["grey"] = 8, m["white"] = 9;
	string a, b, c; cin >> a >> b >> c;
	long long ans = 0;
	ans += m[a] * 10 * 1LL;
	ans += m[b];
	ans *= pow(10, m[c]);
	cout << ans;
	return 0;
}