// https://woongsios.tistory.com/288
#include <bits/stdc++.h>
using namespace std;
string str,str1;
char tmp;
int pri(char a) {
	if (a == '(' || a == ')')
		return 3;
	if (a == '*' || a == '/')
		return 2;
	else return 1;
}
int main() {
	cin >> str;
	stack<char> s;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ')') {
			while (s.top() != '(') {
				tmp = s.top();
				str1 += tmp;
				s.pop();
			} s.pop();
		}
		else if (str[i] == '(' || str[i] == ')' || str[i] == '*' || str[i] == '-' || str[i] == '+' || str[i] == '/') {
			if (s.empty()) s.push(str[i]);
			else {
				while (!s.empty() && pri(s.top()) >= pri(str[i])) {
					if (s.top() == '(' && str[i] != ')') break;
					str1 += s.top();
					s.pop();
				}
				s.push(str[i]);
			}
		}
		else str1+=str[i];

		if (i == str.size() - 1) {
			while (!s.empty()) {
				str1 += s.top();
				s.pop();
			}
		}
	}
	cout << str1;
	return 0;
}