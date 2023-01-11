#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int> vect;
	int n, tmp;
	cin >> n;
	while (n--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	cout << vect[0] * vect[vect.size() - 1];
	return 0;
}