#include <bits/stdc++.h>
using namespace std;
char a[3001], b[3001];
string t1, t2;
int dp[1001][1001];
int main() {
	cin >> t1 >> t2;
	strcpy(a, t1.c_str());
	strcpy(b, t2.c_str());
	for (int i = 3; i<=t1.size(); i+=3) {
		for (int j = 3; j<=t2.size(); j+=3) {
			if (a[i-3] == b[j-3] && a[i - 2] == b[j - 2] && a[i - 1] == b[j - 1])
				dp[i/3][j/3] = dp[i/3 - 1][j/3 - 1] + 1;
			else
				dp[i/3][j/3] = max(dp[i/3][j/3 - 1], dp[i/3 - 1][j/3]);
		}
	}
	cout << dp[t1.size()/3][t2.size()/3];
	return 0;
}