#include <bits/stdc++.h>
using namespace std;

int N, good;
stack<char> st;
string a;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> a;
		while (!st.empty())
			st.pop();
		for (char ch : a) {
			if (!st.empty() && st.top() == ch)
				st.pop();
			else
				st.push(ch);
		}
		if (st.empty())
			good++;
	}
	cout << good;
	return 0;
}
