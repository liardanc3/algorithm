#include <bits/stdc++.h>
using namespace std;
int N;
string tmp;
vector<string> vect;
bool cmp(const string& s1, const string& s2) {
	if (s1.size() != s2.size())
		return s1.size() < s2.size();
	int s1sum = 0, s2sum = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (0 <= s1[i] - '0' && s1[i] - '0' <= 9)
			s1sum += s1[i] - '0';
		if (0 <= s2[i] - '0' && s2[i] - '0' <= 9)
			s2sum += s2[i] - '0';
	}
	if (s1sum != s2sum)
		return s1sum < s2sum;
	return s1 < s2;
}
int main() {
	cin >> N;
	while (N--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end(), cmp);
	for (string s : vect)
		cout << s << '\n';
	return 0;
}