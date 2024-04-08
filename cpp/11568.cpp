#include <bits/stdc++.h>
using namespace std;
int n, tmp;
vector<int> vect;
int main() {
	cin >> n;
	while (n--) {
		cin >> tmp;
		if (vect.empty() || vect[vect.size() - 1] < tmp)
			vect.push_back(tmp);
		else {
			int idx = lower_bound(vect.begin(), vect.end(), tmp) - vect.begin();
			vect[idx] = tmp;
		}
	}
	cout << vect.size();
	return 0;
}