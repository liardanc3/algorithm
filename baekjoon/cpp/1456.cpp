#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool prime[10000001];
ll i, j, now, A, B, ans = 0, mx = LLONG_MAX, bf;
int main() {
	ios_base::sync_with_stdio(NULL);
	cout.tie(NULL); cin.tie(NULL);
	cin >> A >> B;
	for (i = 2; i * i <= B; i++) {
		if (!prime[i]) {
			for (j = 2 * i; j * j <= B; j += i)
				prime[j] = 1;
			bf = i;
			for (now = i * i; now % bf == 0 && now <= B; now *= i) {
				bf = now;
				if (now < A) continue;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}