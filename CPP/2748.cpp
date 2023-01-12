#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n; cin >> n;
	ll F[91]{ 0, };
	F[0] = 0, F[1] = 1;
	for (int i = 2; i <= n; i++)
		F[i] = F[i - 1] + F[i - 2];
	cout << F[n];
	return 0;
}