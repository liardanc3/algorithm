#include <bits/stdc++.h>
using namespace std;

int N, K, prime[1001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	for (int i = 2; i <= N; i++) {
		if (!prime[i]) {
			for (int j = i; j <= N; j += i) {
				if (!prime[j]) {
					K--;
					if (K == 0) {
						cout << j;
						return 0;
					}
					prime[j] = 1;
				}
			}
		}
	}
	return 0;
}
