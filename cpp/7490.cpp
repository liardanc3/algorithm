#include <bits/stdc++.h>
using namespace std;
int t, n;
void dfs(int idx, string s) {
	if (idx == n) {
		int sum = 0;
		int tmp = 0;

		int bef = 0;
		// 0+ 1-
		for (int i = 0; i < s.size(); i++) {
			if ('1' <= s[i] && s[i] <= '9')
				tmp += (s[i] - '0');
			else if (s[i] == ' ')
				tmp *= 10;
			else {
				bef ? sum -= tmp : sum += tmp;
				bef = s[i]=='+' ? 0 : 1;
				tmp = 0;
			}
		}
		bef ? sum -= tmp : sum += tmp;

		if (sum == 0)
			cout << s << '\n';
		return;
	}
	bool flag = s[s.size() - 1] == '+' || s[s.size() - 1] == '-' || s[s.size() - 1] == ' ';
	if (!flag) {
		dfs(idx, s + ' ');
		dfs(idx, s + '+');
		dfs(idx, s + '-');
	}
	else
		dfs(idx + 1, s + (char)((idx + 1) + '0'));
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		dfs(1, "1");
		cout << '\n';
	}
	return 0;
}