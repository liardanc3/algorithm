#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll X, Y, W, S;
	cin >> X >> Y >> W >> S;
	if (2 * W < S)
		cout << W * (X + Y);
	else if (W > S && (X + Y) % 2 == 0)
		cout << S * max(X,Y);
	else if (W > S && (X + Y) % 2 == 1)
		cout << S * (max(X,Y)-1) + W;
	else cout << S * min(X, Y) + W * (max(X, Y) - min(X, Y));
}