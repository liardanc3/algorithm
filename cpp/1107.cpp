#include <bits/stdc++.h>
using namespace std;
int imposs[10];

int check_possible(int test) {
	string stmp = to_string(test);
	for (int i = 0; i < stmp.size(); i++) {
		if (imposs[stmp[i] - '0'] == 0) return 0;
		else if (i == stmp.size() - 1)
			return 1;
	}
	return -1;
}

int main() {
	fill(imposs, &imposs[10], 1);
	int N, M, tmp, ans = -1; cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> tmp; imposs[tmp] = 0;
	}
	for (int i = -2; i < 3; i++) {
		if (N == (100 + i)) {
			cout << abs(i); return 0;
		}
	}
	int i = 0;
	if (check_possible(N)) cout << to_string(N).size();
	else {
		while (true) {
			i++;
			if (N - i == 100 || N + i == 100) {
				ans = i; break;
			}
			if (N - i >= 0) {
				int dn = check_possible(N - i);
				if (dn == 1) {
					ans = min((int)to_string(N - i).size() + i, abs(100 - N));
					break;
				}
			}
			int up = check_possible(N + i);
			if (up == 1) {
				ans = min((int)to_string(N + i).size() + i, abs(100 - N));
				break;
			}
		}
		cout << ans;
	}
	return 0;
}