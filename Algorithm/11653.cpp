#include <bits/stdc++.h>
using namespace std;
int prime[3164];
// 1=소수아님 0=소수
int main() {
	prime[1] = 1;
	for (int i = 2; i <= 3163; i++) {
		for (int j = 2; j * j < i; j++) {
			if (i % j == 0)
				prime[i] = 1;
		}
	}
	int N; cin >> N;
	vector<int> vect;
	
	if (N == 1) return 0;
	for (int i = 2; i <= 3163 && N != 1; i++) {
		if (prime[i] == 0 && N % i == 0) {
			vect.push_back(i);
			N /= i;
			i = 1;
		}
	}
	if (N != 1)
		vect.push_back(N);
	sort(vect.begin(), vect.end());
	for (int a : vect) cout << a << '\n';
	
	return 0;
}