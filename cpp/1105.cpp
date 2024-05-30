#include <bits/stdc++.h>
using namespace std;

int main() {
	string L, R;
	cin >> L >> R;
	if (L.size() != R.size()) cout << 0;
	else {
		int cnt = 0;
		for (int i = 0; i < L.size(); i++) {
			if (L[i] != R[i]) {
				cout << cnt;
				return 0;
			}
			if (L[i] == R[i] && L[i]=='8')
				cnt++;
		}
		cout << cnt;
		return 0;
	}
	return 0;
}