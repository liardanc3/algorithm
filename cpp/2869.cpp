#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, v;
	cin >> a >> b >> v;
	v -= a;
	int ans = v / (a - b);
	ans++;
	if (v % (a - b) != 0) ans++;
	cout << ans;
	return 0;
}