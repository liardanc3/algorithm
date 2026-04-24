#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, tmp;
	cin >> n;
	vector<int> vect;
	while (n--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.rbegin(), vect.rend());
	int mx = vect[0];
	double sum = 0;
	for (int i : vect) {
		sum += 1.f * i / mx * 100.f;
	}
	cout << sum / vect.size();
	return 0;
}