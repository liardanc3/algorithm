#include <bits/stdc++.h>
#define int long long
#define DIV 1'000'000
using namespace std;

typedef tuple<int, int, int, int> tii;

tii mul(tii a, tii b) {
	int a1 = get<0>(a), a2 = get<1>(a), a3 = get<2>(a), a4 = get<3>(a);
	int b1 = get<0>(b), b2 = get<1>(b), b3 = get<2>(b), b4 = get<3>(b);
	int r1 = ((a1 * b1) % DIV + (a2 * b3) % DIV) % DIV;
	int r2 = ((a1 * b2) % DIV + (a2 * b4) % DIV) % DIV;
	int r3 = ((a3 * b1) % DIV + (a4 * b2) % DIV) % DIV;
	int r4 = ((a3 * b2) % DIV + (a4 * b4) % DIV) % DIV;
	return { r1,r2,r3,r4 };
}

tii POW(tii t, int p) {
	if (p == 1)
		return t;
	tii tmp = POW(t, p / 2);
	
	if (p % 2)
		tmp = mul(t, mul(tmp, tmp));
	else
		tmp = mul(tmp, tmp);

	return tmp;
}

int n;
signed main() {
	cin >> n;
	tii t = POW({ 1,1,1,0 },n);
	cout << get<2>(t) % DIV;
	return 0;
}