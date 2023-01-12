#include <bits/stdc++.h>
using namespace std;

int main() {
	int T,tmp,ans,mod,val; cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> tmp;
		mod = tmp % 28;
		if (mod == 0) ans = 2;
		else mod > 15 ? ans = 30 - mod : ans = mod;
		
		for (int j = 8; j >= 1; j /= 2) {
			if (ans / j != 0) {
				cout << "µþ±â";
				ans -= j;
			}
			else cout << "V";
		}
		cout << "\n";
	}
}