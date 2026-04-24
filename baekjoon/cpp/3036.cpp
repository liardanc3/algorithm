#include <bits/stdc++.h>
using namespace std;

int N, tmp;
vector<int> vect;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}

	for (int i = 1; i < N; i++) {
		int _gcd = gcd(vect[0], vect[i]);
		cout << vect[0] / _gcd << '/' << vect[i] / _gcd << '\n';
	}

	return 0;
}
