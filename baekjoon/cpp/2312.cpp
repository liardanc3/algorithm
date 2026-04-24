#include <bits/stdc++.h>
using namespace std;

int T, N, cnt;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 2; i * i <= N; i++) {
			if (N % i == 0)
				cout << i << ' ';
			for (cnt = 1; N % i == 0; cnt++) 
				N /= i;
			if(cnt>1)
				cout << cnt-1 << '\n';
		}
		if (N != 1)
			cout << N << ' ' << 1 << '\n';
	}
	return 0;
}