#include <bits/stdc++.h>
using namespace std;
int main() {
	int d[2001]{ 0, }, n, i;
	cin >> n; i = 0;
	while (++i <= n) cin >> d[1000 + i];
	while (1000 + i - n <= 1000 + i - 1)
		d[d[1000 + i - (n--)]] = *max_element(d, d + d[1000 + i - n]) + 1;
	cout << *max_element(d, d + 1001);
	return 0;
}