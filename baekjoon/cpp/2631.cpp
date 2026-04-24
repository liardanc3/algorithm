#include <bits/stdc++.h>
using namespace std;
int n, arr[201]{ 0, };
vector<int> vect;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	vect.push_back(arr[1]);
	for (int i = 2; i <= n; i++) {
		int now = arr[i];
		if (vect[vect.size() - 1] < now)
			vect.push_back(now);
		else {
			int idx = lower_bound(vect.begin(), vect.end(), now) - vect.begin();
			vect[idx] = now;
		}
	}
	cout << n - vect.size();
	return 0;
}