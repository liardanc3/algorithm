#include <bits/stdc++.h>
using namespace std;

string str, ans;
int M;
char cmd, ch;
stack<char> a, b;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> str >> M;
	for (char c : str)
		a.push(c);
	while (M--) {
		cin >> cmd;
		if (cmd == 'L') {
			if (a.empty())
				continue;
			b.push(a.top());
			a.pop();
		}
		else if (cmd == 'D') {
			if (b.empty())
				continue;
			a.push(b.top());
			b.pop();
		}
		else if (cmd == 'B') {
			if (a.empty())
				continue;
			a.pop();
		}
		else {
			cin >> ch;
			a.push(ch);
		}
	}
	while (!a.empty()) {
		ans += a.top();
		a.pop();
	}
	reverse(ans.begin(), ans.end());
	while (!b.empty()) {
		ans += b.top();
		b.pop();
	}
	cout << ans;
	return 0;
}