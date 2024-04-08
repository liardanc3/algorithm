#include <bits/stdc++.h>
using namespace std;
int n, k, tmp;
vector<int> vect;
vector<int> gap;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	vect.erase(unique(vect.begin(), vect.end()), vect.end());
	// 1 3 6 7 9
	for (int i = 0; i < vect.size()-1; i++) 
		gap.push_back(vect[i + 1] - vect[i]);
	sort(gap.rbegin(), gap.rend());
	int ans = vect[vect.size() - 1] - vect[0];
	int idx = 0;
	k--;
	while (k-- && gap.size() > idx) {
		ans -= gap[idx++];
	}
	cout << ans;
	return 0;
}