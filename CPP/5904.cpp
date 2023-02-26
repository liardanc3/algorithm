#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, len[28], m;
int S(int idx, int k) {
	if (k == 0) 
		return idx == 1;

	int len1 = len[k - 1];
	int len2 = 1 + k + 2;
	int len3 = len[k - 1];

	if (idx <= len1) 
		return S(idx, k - 1);
	if (idx <= len1 + len2)
		return (idx) == (len1 + 1);
	if (idx <= len1 + len2 + len3)
		return S(idx - len2 - len3, k - 1);
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;

	[&]() {
		len[0] = 3;
		for (int i = 1; i <= 27; i++)
			len[i] = len[i - 1] * 2 + 1 + i + 2;

		for (int i = 27; i >= 0; i--) {
			if (n <= len[i])
				m = i;
			else
				break;
		}
	}();
	
	if (S(n, m))
		cout << 'm';
	else
		cout << 'o';
	return 0;
}