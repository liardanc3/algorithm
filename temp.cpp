#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> vect;
bool cmp(const string& a, const string& b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	return a < b;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> s;
		vect.push_back(s);
	}
	sort(vect.begin(), vect.end(), cmp);
	vect.erase(unique(vect.begin(), vect.end()), vect.end());
	for (string str : vect)
		cout << str << '\n';
	return 0;
}