#include <bits/stdc++.h>
#define int long long
using namespace std;
string s, tmp;
stack<char> st;
int ans = 0, depth = 0;
int multiply[52], layer[52];
signed main() {
	s = "1(";
	cin >> tmp;
	s += tmp + ')';
	for (int i = 0; i < s.size(); i++) {
		char now = s[i];
		if (i + 1 < s.size() && s[i + 1] == '(') 
			multiply[++depth] = (int)(now - '0');

		if (now != ')')
			st.push(now);
		else {
			int tmp = 0;
			while (st.top() != '(' && st.top() != ')') {
				tmp++;
				st.pop();
			}
			
			layer[depth - 1] += (tmp+layer[depth]) * multiply[depth];
			layer[depth] = 0;
			if (st.top() == '(') {
				st.pop();
				st.pop();
				depth--;
			}
		}
	}
	cout << layer[0];
	
	return 0;
}