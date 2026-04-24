#include <bits/stdc++.h>
using namespace std;
#define DIV 1000000007
typedef long long ll;
typedef vector<vector<ll>> mat;
mat vect;
mat x(mat a, mat b) {
	mat c;
	for (int i = 0; i < 2; i++) {
		vector<ll> tmp;
		for (int j = 0; j < 2; j++) {
			ll tp=0;
			for (int k = 0; k < 2; k++) {
				tp += (a.at(i).at(k) * b.at(k).at(j)) % DIV;
				tp %= DIV;
			}
			tmp.push_back(tp);
		}
		c.push_back(tmp);
	}
	return c;
}
mat POW(mat a, ll n) {
	if (n == 1)
		return a;
	mat hf = POW(a, n / 2);
	hf = x(hf, hf);
	if (n % 2 == 1)
		return x(hf, a);
	return hf;
}
int main() {
	ll n; cin >> n;
	vector<ll> tmp;
	tmp.push_back(1);
	tmp.push_back(1);
	vect.push_back(tmp);
	tmp.clear();
	tmp.push_back(1);
	tmp.push_back(0);
	vect.push_back(tmp);
	mat ANS = POW(vect, n);
	cout << ANS.at(0).at(1);
	return 0;
}