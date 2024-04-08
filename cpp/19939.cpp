#include <bits/stdc++.h>
using namespace std;

int N, K;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	if (N < (K * (K + 1)) / 2)
		cout << -1;
	else {
		N -= (K * (K + 1)) / 2;

		if (N % K)
			cout << K;
		else
			cout << K - 1;
	}


	// 8 3

	// 1 2 3

	return 0;
}
