#include <bits/stdc++.h>
using namespace std;
int t, n, arr[2], tmp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		memset(arr, 0, sizeof(arr));
		cin >> n;
		while (n--) {
			cin >> tmp;
			arr[tmp % 2]++;
		}
		cout << min(arr[0], arr[1]) << '\n';
	}
	return 0;
}