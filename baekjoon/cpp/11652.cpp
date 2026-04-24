#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, tmp, mxcnt, num;
map<int, int> m;
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> tmp;
		m[tmp]++;
		int cnt = m[tmp];
		if (mxcnt < cnt) {
			mxcnt = cnt;
			num = tmp;
		}
		else if (mxcnt == cnt && num > tmp)
			num = tmp;
	}
	cout << num;
	return 0;
}
