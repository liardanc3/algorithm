#include <bits/stdc++.h>
using namespace std;
string c[101][101];

string str_add(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (b.size() > a.size()) {
		string tmp = a;
		a = b;
		b = tmp;		
	}
	string ans = "";
	int upper = 0;
	for (int i = 0; i < b.size(); i++) {
		int ckp1 = (a[i] - '0') + (b[i] - '0') + upper;
		upper = ckp1 / 10; ckp1 %= 10;
		ans += (char)(ckp1 + 48);
	}
	for (int i = b.size(); i < a.size(); i++) {
		int ckp2 = (a[i] - '0') + upper;
		upper = ckp2 / 10; ckp2 %= 10;
		ans += (char)(ckp2 + 48);
	}
	if (upper != 0) ans += (char)(upper + 48);
	reverse(ans.begin(), ans.end());
	return ans;
}

string dp(int n, int m) {
	if (c[n][m].compare("0")!=0) {
		return c[n][m];
	}
	else {
		if (m == 0) c[n][m] = dp(n - 1,0);
		else if (m == n) c[n][m] = dp(n - 1, m - 1);
		else c[n][m] = str_add(dp(n - 1, m - 1),dp(n - 1, m));
	}
	return c[n][m];
}

int main() {
	fill(&c[0][0], &c[100][101], "0");
	c[1][0] = "1"; c[1][1] = "1";
	int n, m; cin >> n >> m;
	cout << dp(n, m);
	return 0;
}