#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, tmp, sum, mn=1e9, idx;
vector<int> vect, prefix;
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> tmp;
		vect.push_back(tmp);
		sum += tmp;
	}
	sort(vect.begin(), vect.end());
	prefix.push_back(vect[0]);
	for (int i = 1; i < vect.size() - 1; i++) 
		prefix.push_back(prefix[i-1] + vect[i]);
	mn = sum - vect[0] * vect.size();
	for (int i = 1; i < vect.size(); i++) {
		int now = sum - (vect[i] * (vect.size() - i))
			+ ((i * vect[i]) - prefix[i - 1]) - prefix[i-1];
		if (now < mn) {
			mn = now;
			idx = i;
		}
	}
	cout << vect[idx];
	return 0;
}