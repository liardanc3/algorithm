#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, M, N, X, Y, k, ans;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> X >> Y;
		k = -1;
		if (X > Y) {
			int tmp = Y;
			Y = X;
			X = tmp;
			tmp = N;
			N = M;
			M = tmp;
		}
		for (int i = 0; i < N; i++) {
			if ((M * i) % N == Y - X) {
				k = i; break;
			}
		}
		k==-1? ans = -1 : ans=M*k+X;
		cout << ans << '\n';
	}
	return 0;
}