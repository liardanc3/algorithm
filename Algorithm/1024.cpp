#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
	ld N; ll L; cin >> N >> L;
	for (ll i = L; i<=100; i++) {
		ld a = (N - i * (i + 1) / 2.f) / (i * 1.f) + 1;
		if (a == floor(a) && a>=0) {
			for (int j = a; j < a + i; j++) 
				cout << j << ' ';
			return 0;
		}
	}
	cout << -1;
	return 0;
}