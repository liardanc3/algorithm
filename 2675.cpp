#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; string tmp;
		cin >> n >> tmp;
		for (int i = 0; i < tmp.size(); i++) {
			for (int j = 0; j < n; j++)
				cout << tmp[i];
		}
		cout << '\n';
	}
	return 0;
}