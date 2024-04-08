#include <bits/stdc++.h>
#include <exception>
#define ERROR(x) if(x)error();
#define int long long
using namespace std;

string tmp;
int sum;
stack<int> st;
void error() {
	cout << 0;
	exit(0);
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> tmp;
	for (int ch : tmp) {
		if (ch == 40 || ch == 91) {
			st.push(-ch);
		}
		else {
			if (ch == 41) {
				ERROR(st.empty());
				if (st.top() == -40) {
					st.pop();
					st.push(2);
				}
				else {
					int tmp = 0;
					while (!st.empty() && st.top() != -40) {
						tmp += st.top();
						st.pop();
					}
					ERROR(st.empty());
					st.pop();
					st.push(2 * tmp);
				}
			}
			else {
				ERROR(st.empty());
				if (st.top() == -91) {
					st.pop();
					st.push(3);
				}
				else {
					int tmp = 0;
					while (!st.empty() && st.top() != -91) {
						tmp += st.top();
						st.pop();
					}
					ERROR(st.empty());
					st.pop();
					st.push(3 * tmp);
				}
			}
		}
	}
	ERROR(st.empty());
	while (!st.empty()) {
		ERROR(st.top() < 0);
		sum += st.top();
		st.pop();
	}
	cout << sum;
	return 0;
}