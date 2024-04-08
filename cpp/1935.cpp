#include <bits/stdc++.h>
using namespace std;
int N, num;
string tmp;
map<char, double> m;
stack<double> st;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> tmp;
	for (int i = 0; i < N; i++) {
		cin >> num;
		m['A' + i] = 1.f * num;
	}
	for (char ch : tmp) {
		if ('A' <= ch && ch <= 'Z')
			st.push(m[ch]);
		else {
			double b = st.top(); st.pop();
			double a = st.top(); st.pop();
			
			if (ch == '*')
				st.push(a * b);
			else if (ch == '+')
				st.push(a + b);
			else if (ch == '/')
				st.push(a / b);
			else
				st.push(a - b);
		}
	}
	cout << fixed << setprecision(2) << st.top();
	return 0;
}
