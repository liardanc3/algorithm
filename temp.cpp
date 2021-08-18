#include <iostream>	
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, tmp; cin >> T;
	int up = 1;
	int ans;
	for (int i = 0; i < T; i++) {
		cin >> tmp;
		ans = 16;
		for (int j = 0; j < tmp; j++) {
			if (ans == 31) up = 0;
			if (ans == 17) up = 1;
			if (up) {
				if (tmp - j > 12) ans += 13;
				else ans++;
			}
			else {
				if (tmp - j > 12) ans -= 13;
				else ans--;
			}
		}
		ans -= 16;
		for (int j = 8; j >= 1; j /= 2) {
			if (ans / j != 0) {
				cout << "µþ±â"; ans -= j;
			}
			else cout << "V";
		}
	}
	return 0;
}