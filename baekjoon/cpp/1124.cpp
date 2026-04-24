#include <bits/stdc++.h>
using namespace std;
int A, B, _prime[100001]{ 0, };
vector<int> prime;
void init() {
	_prime[2] = 1, _prime[3] = 1;
	prime.push_back(2), prime.push_back(3);
	for (int i = 5; i <= 100000; i++) {
		bool flag = true;
		for (int j = 0; prime[j] * prime[j] <= i; j++) {
			if (i % prime[j] == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			prime.push_back(i);
			_prime[i] = 1;
		}
	}
}
int isUnderPrime(int n) {
	int cnt = 0;
	for (int i = 0; i < prime.size() && n >= prime[i]; i++) {
		if (n % prime[i] == 0) {
			cnt++;
			n /= prime[i];
			i = -1;
		}
	}
	return _prime[cnt];
}
int main() {
	init();
	cin >> A >> B;
	int cnt = 0;
	for (int i = A; i <= B; i++) {
		if (_prime[i]) continue;
		cnt += isUnderPrime(i);
	}
	cout << cnt;
	return 0;
}