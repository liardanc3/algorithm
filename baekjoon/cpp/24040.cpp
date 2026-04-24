#include <bits/stdc++.h>
#define MAX 1e19
using namespace std;
typedef long long ll;
ll T, N;
vector<ll> prime;
void init() {
	prime.push_back(1), prime.push_back(2), prime.push_back(3);
	for (ll i = 5; i <= MAX; i++) {
		bool flag = true;
		for (ll j = 1; prime[j] * prime[j] <= i; j++) {
			if (i % prime[j] == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			prime.push_back(i);
			if(i>=1e10)
				cout << i << '\n';
		}
			
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	init();
	cin >> T;
	while (T--) {
		cin >> N;
		bool flag = false;
		for (ll i = 0; prime[i] * prime[i] <= N && i<prime.size(); i++) {
			if (N % prime[i] == 0) {
				ll left = prime[i];
				ll right = N / prime[i];
				ll length = 2 * (left + right);
				if (length % 3 == 0) {
					flag = true;
					cout << "TAK" << '\n';
					break;
				}
			}
		}
		if (!flag)
			cout << "NIE" << '\n';
	}
	return 0;
}