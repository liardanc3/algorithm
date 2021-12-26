#include <bits/stdc++.h>
using namespace std;
int prime[1000001]{ 0, };
int vect[1000001]{ 0, };
int idx = 0;
void makeprime() {
	fill(&prime[0], &prime[1000001], 1);
	for (int i = 3; i*i<= 1000000; i+=2) {
		for (int j = i+i; j<=1000000; j+=i) 
			prime[j] = 0;
		if (prime[i]) 
			vect[idx++] = i;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	makeprime();
	int n;
	while (cin >> n) {
		if (n == 0) break;
		bool flag = true;
		for (int i = 0; i < idx && vect[i] <= n-3; i++) {
			if (prime[n - vect[i]]) {
				cout << n << " = " << vect[i] << " + " << n - vect[i] << '\n';
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "Goldbach's conjecture is wrong." << '\n';
		}
	}
	return 0;
}