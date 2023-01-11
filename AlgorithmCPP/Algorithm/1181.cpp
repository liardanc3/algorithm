#include <bits/stdc++.h>
using namespace std;
bool cmp(const string &s1, string &s2) {
	if(s1.size()!=s2.size())
		return s1.size() < s2.size();
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i])
			return s1[i] - '0' < s2[i] - '0';
	}
}
int main() {
	vector<string> vect;
	int n; cin >> n;
	string tmp;
	while (n--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	vect.erase(unique(vect.begin(), vect.end()), vect.end());
	sort(vect.begin(), vect.end(), cmp);
	for (string s : vect)
		cout << s << '\n';
	return 0;
}

