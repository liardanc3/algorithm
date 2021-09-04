#include <bits/stdc++.h>
using namespace std;
int main() {
	string str = "123123 anasd djalsd";
	char* ctr = (char*)str.c_str();
	char* tmp;
	tmp = strtok_s(ctr, " ", &ctr);
	while (tmp) {
		cout << tmp;
		tmp = strtok_s(ctr, " ", &ctr);
	}
	stack<int> st;
	st.
}