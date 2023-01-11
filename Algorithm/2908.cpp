#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int aa = stoi(a);
	int bb = stoi(b);
	aa > bb ? printf("%d", aa) : printf("%d", bb);
	return 0;
}