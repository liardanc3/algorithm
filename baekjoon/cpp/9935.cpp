#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string inp, tok, ans = "";
	cin >> inp >> tok;
	stack<char> s;
	stack<char> s_tmp;
	char last = tok.at(tok.length() - 1);
	for (int i = 0; i < inp.length(); i++) {
		s.push(inp[i]);
		if (inp[i] == last) {
			for (int j = 0; j < tok.length(); j++) {
				if (!s.empty() && tok[tok.length() - 1 - j] == s.top()) {
					s_tmp.push(s.top());
					s.pop();
				}
				else {
					while (!s_tmp.empty()) {
						s.push(s_tmp.top());
						s_tmp.pop();
					}
					break;
				}
			}
			while (!s_tmp.empty())
				s_tmp.pop();
		}
	}
	while (!s.empty()) {
		ans += s.top(); s.pop();
	}
	reverse(ans.begin(), ans.end());
	if (ans == "")
		cout << "FRULA";
	else cout << ans;
	return 0;
}