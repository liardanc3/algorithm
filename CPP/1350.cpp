#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<long long> vect;
	long long n, s, c, use = 0;
	cin >> n;
	while (n--) {
		cin >> s;
		vect.push_back(s);
	}
	cin >> c;
	for (int i = 0; i < vect.size(); i++) {
		long long now = vect[i];
		use += (now / c + 1);
		if (now % c == 0) use--;
	}
	cout << use * c;
	return 0;
}