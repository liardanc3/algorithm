#include <bits/stdc++.h>
using namespace std;
int n, tmp;
vector<int> v1, vect;
int main() {
	cin >> n;
	while (n--) {
		cin >> tmp;
		v1.push_back(tmp);
	}
	reverse(v1.begin(), v1.end());
	vect.push_back(v1[0]);
	for (int i = 1; i < v1.size(); i++) {
		if (vect[vect.size() - 1] < v1[i])
			vect.push_back(v1[i]);
		else {
			int idx = lower_bound(vect.begin(), vect.end(), v1[i]) - vect.begin();
			vect[idx] = v1[i];
		}
	}
	cout << vect.size();
	return 0;
}