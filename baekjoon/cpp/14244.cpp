#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	m--;
	int start = 0;
	for (int i = 1; i < n; i++) {
		if (m < n-i) {
			cout << start << ' ' << i << '\n';
			start++;
		}
		else
			cout << start << ' ' << i << '\n';		
	}
	return 0;
}