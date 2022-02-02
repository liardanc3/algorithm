#include <bits/stdc++.h>
#define int long long
#define DIV 1'000'000'007
using namespace std;
typedef tuple<int, int, int, int> matrix;
int n;
matrix MUL(matrix m1, matrix m2) {
	int a, b, c, d;
	a = get<0>(m1) * get<0>(m2) + get<1>(m1) * get<2>(m2);
	b = get<0>(m1) * get<1>(m2) + get<1>(m1) * get<3>(m2);
	c = get<2>(m1) * get<0>(m2) + get<3>(m1) * get<2>(m2);
	d = get<2>(m1) * get<1>(m2) + get<3>(m1) * get<3>(m2);
	return { a%DIV ,b%DIV ,c%DIV ,d%DIV };
}
matrix POW(int i) {
	if (i == 1)
		return { 0,1,1,1 };
	matrix half = POW(i / 2);
	half = MUL(half, half);
	if (i % 2) half = MUL(half, { 0,1,1,1 });
	return half;
}
signed main() {
	cin >> n;
	if (n == 0) cout << 0;
	else {
		matrix m = POW(n);
		cout << get<1>(m);
	}
	return 0;
}