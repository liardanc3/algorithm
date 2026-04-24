#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, a, b;
	cin >> N >> a >> b;
	if (a > b) swap(a, b);
	int round = 1;
	while (abs(a-b) != 1 || !(a%2) || b%2) {
		if (a % 2)
			a++;
		a /= 2;
		if (b % 2)
			b++;
		b /= 2;
		round++;
	}
	cout << round;
	return 0;
}