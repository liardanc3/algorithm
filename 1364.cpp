#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n, ans = 0; cin >> n;
	if (n <= 5) cout << n;
	else {
		ll len = n / 6;
		ll gap = n - 6 * len;
		ll stick[6]{ 0, };
		fill(&stick[0], &stick[6], len);
		for (int i = 0; i < gap; i++)
			stick[i]++;
		ll ans = 0;
		bool flag = false;
		while (!flag){
			flag = true;
			for (int i = 0; i < 6; i++) {
				ans += stick[i];
				if(stick[i]>0) stick[i]--;
				if (stick[i] > 0) flag = false;
			}
		}
		if (n % 6 == 0) ans++;
		cout << ans;
	}

	// 1 6 12 18 24 
	// 1 -> 1
	// 2 -> 2
	// 3 -> 3
	// 4 -> 4
	// 5 -> 5
	//// 6 -> 7
	// 7 -> 8
	// 8 -> 10
	// 9 -> 12
	// 10 -> 14
	// 11 -> 16
	//// 12 -> 19
	// 13 -> 21
	// 14 -> 25
	// 15 -> 27
	// 16 -> 30
	return 0;
}