#include <bits/stdc++.h>
using namespace std;
int A, B, N, ret;
signed main() {
    cin >> A >> B >> N;
	for (int i = A < B ? 1 : 0; i <= N; i++) {
		if (A < B)
			A *= 10;
		ret = A / B;
		A -= (A / B) * B;
	}
	cout << ret;
	return 0;
}