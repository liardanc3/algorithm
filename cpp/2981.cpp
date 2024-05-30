#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, tmp;
vector<int> vect, ans;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
signed main() {
	cin >> n;
	while (n--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	int res = vect[1] - vect[0];
	for (int i = 1; i < vect.size(); i++) {
		res = gcd(res, vect[i] - vect[i - 1]);
	}
	for (int i = 1; i * i <= res; i++) {
		if (res % i == 0) {
			ans.push_back(i);
			ans.push_back(res / i);
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i = 1; i < ans.size(); i++)
		cout << ans[i] << ' ';
	return 0;
}