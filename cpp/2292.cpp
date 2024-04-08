#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n; cin >> n;

	// 0 +6 +12 +18 
	if (n == 1) cout << 1;
	else {
		n--;
		int cnt = 0;
		int init = 0;
		int gap = 6;
		while (init<n) {
			init += gap;
			cnt++;
			gap += 6;
		}
		cout << 1 + cnt;
	}
	

	return 0;
}