#include <bits/stdc++.h>
using namespace std;

int t;
deque<char> a; stack<char> b;
string str;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		while (a.size())
			a.pop_back();
		while (b.size())
			b.pop();
		cin >> str;
		for (char ch : str) {
			if (ch == '<') {
				if (!a.empty()) {
					b.push(a.back());
					a.pop_back();
				}
			}
			else if (ch == '>') {
				if (!b.empty()) {
					a.push_back(b.top());
					b.pop();
				}
			}
			else if (ch == '-') {
				if (!a.empty())
					a.pop_back();
			}
			else
				a.push_back(ch);
		}
		while (!a.empty()) {
			cout << a.front();
			a.pop_front();
		}
		while (!b.empty()) {
			cout << b.top();
			b.pop();
		}
		cout << '\n';
	}
	return 0;
}