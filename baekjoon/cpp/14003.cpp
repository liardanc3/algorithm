#include <bits/stdc++.h>
using namespace std;
int n, dp[1000000], last, arr[1000000];
vector<int> vect;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0) {
			vect.push_back(arr[i]);
			dp[i] = 1;
		}
		else {
			int idx = lower_bound(vect.begin(), vect.end(), arr[i]) - vect.begin();
			dp[i] = idx + 1;
			if (vect[vect.size()-1] < arr[i]) {
				vect.push_back(arr[i]);
				last = i;
			}
			else {
				vect[idx] = arr[i];
			}
		}
	}
	int size = vect.size();
	cout << size << '\n';
	int now_size = 1;
	for (int i = 0; i <= last && now_size <= size; i++) {
		if (dp[i] == now_size) {
			cout << arr[i] << ' ';
			now_size++;
		}
	}
	return 0;
}