#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b; cin >> a >> b;
	int mn = 1e9;
	for (int i = 0; i <= b.size() - a.size(); i++) {
		int tmp = 0;
		int idx = 0;
		for (int j = i; j < i + a.size(); j++) {
			if (a[idx++] != b[j])
				tmp++;
		}
		mn = min(mn, tmp);
	}
	cout << mn;

	return 0;
}