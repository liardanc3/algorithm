#include <bits/stdc++.h>
#define int long long
#define DIV 10'007
using namespace std;

int N, C[53][53], ans;
signed main() {
	C[0][0] = 1;
	C[1][0] = 1, C[1][1] = 1;
	for (int i = 2; i <= 52; i++) {
		C[i][0] = 1, C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % DIV;
	}
	cin >> N;
	if (N < 4)
		cout << 0;
	else {
		int flag = 1;
		for (int i = 4, j = 1; N >= i; i += 4, j++) {
			int add = ((C[13][j] % DIV) * (C[52 - i][N - i] % DIV)) % DIV;
			flag ? ans += add : ans -= add;
			ans %= DIV;
			flag = !flag;
		}		
		if (ans < 0)
			ans += DIV;
		cout << ans;
	}
	return 0;
}