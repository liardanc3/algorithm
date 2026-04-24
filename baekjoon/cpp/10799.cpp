#include <bits/stdc++.h>
using namespace std;

string str;
int cnt, bef;
stack<char> st;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> str;
	for (char ch : str) {
		if (ch == '(')
			st.push(ch), bef = 1;
		else {
			if (bef) {
				st.pop();
				cnt += st.size();
			}
			else
				st.pop(), cnt++;
			bef = 0;
		}
	}
	cout << cnt;
	return 0;
}