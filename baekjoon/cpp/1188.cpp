#include <bits/stdc++.h>
using namespace std;
int N, M;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	cin >> N >> M;	
	N %= M;
	cout << M - gcd(M, N);
	return 0;
}