#include <bits/stdc++.h>
using namespace std;

int main() {
	int X; cin >> X;
	vector<int> vect;
	vect.push_back(64);
	int sum = 64;
	while (sum > X) {
		sort(vect.begin(), vect.end());
		int step1 = vect[0] / 2;
		vect.erase(vect.begin());
		vect.push_back(step1);
		if (sum - step1 < X) {
			vect.push_back(step1);
		}
		else {
			sum -= step1;
		}
	}
	cout << vect.size();

	return 0;
}