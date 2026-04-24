#include <iostream>
#define int long long
using namespace std;

int N, H_atk, type, at, health, mx, H_cur;
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	cin >> N >> H_atk;
	while(N--) {
		cin >> type >> at >> health;

		if (type == 1) {
			int round = health / H_atk;
			if (health % H_atk == 0)
				round--;
			H_cur -= at * round;
			mx = max(mx, -H_cur + 1);
		}

		if (type == 2) {
			H_atk += at;
			H_cur = min(0LL, health + H_cur);
		}
	}
	cout << mx;
	return 0;
}