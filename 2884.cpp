#include <bits/stdc++.h>
using namespace std;
int main() {
	int h, m;
	cin >> h >> m;
	m = m - 45;
	if (m < 0) {
		h--;
		if (h < 0)
			h = 23;
		m = 60 + m;
	}
	cout << h << ' ' << m;
	return 0;
}