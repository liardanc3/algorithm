#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, k, arr[600001], start, cost;
vector<pii> vect;
int main() {
	cin >> n >> k;
	cin >> arr[1];
	for (int i = 3; i <= 2*n; i += 2) {
		cin >> arr[i];
		vect.push_back({ arr[i] - arr[i - 2],i - 1 });
	}
	sort(vect.rbegin(), vect.rend());
	for (int i = 1; i <= k - 1; i++) {
		pii p = vect[i-1];
		arr[p.second] = -1;
	}
	start = arr[1];
	for (int i = 2; i < 2 * n; i++) {
		if (i % 2 == 0) {
			if (arr[i] == -1) {
				cost += arr[i - 1] - start;
				start = 0;
			}
		}
		else {
			if (start == 0)
				start = arr[i];
		}
	}
	cost += arr[2 * n-1] - start;
	cout << cost;
	return 0;
}