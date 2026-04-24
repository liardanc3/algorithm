#include <bits/stdc++.h>
using namespace std;

string tmp;
set<string> s;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> tmp;
	for (int i = 0; i < tmp.size(); i++) {
		string now = "";
		for (int j = i; j < tmp.size(); j++) {
			now += tmp[j];
			s.insert(now);
		}
	}
	cout << s.size();
	return 0;
}
