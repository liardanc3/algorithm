#include <bits/stdc++.h>
using namespace std;
string s;
vector<string> vect;
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		vect.push_back(s.substr(i, s.size()));
	}
	sort(vect.begin(), vect.end());
	for (string str : vect)
		cout << str << '\n';
	return 0;
}