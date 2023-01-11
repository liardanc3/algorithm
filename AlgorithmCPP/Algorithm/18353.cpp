#include <bits/stdc++.h>
using namespace std;
int n, tmp;
vector<int> vect, v;
int main() {
	cin >> n;
	while (n--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	reverse(vect.begin(), vect.end());
	for (int i : vect) {
		if (!v.size() || v[v.size() - 1] < i)
			v.push_back(i);
		else {
			int idx = lower_bound(v.begin(), v.end(), i) - v.begin();
			v[idx] = i;
		}
	}
	cout << vect.size() - v.size();
	return 0;
}