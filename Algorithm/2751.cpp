#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int tmp;
	vector<int> vect;
	while (n--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	for (int it : vect) {
		cout << it << '\n';
	}
	return 0;
}