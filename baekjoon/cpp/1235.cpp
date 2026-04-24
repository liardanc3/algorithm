#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	vector<string> vect;
	string tmp;
	while (N--) {
		cin >> tmp;
		reverse(tmp.begin(), tmp.end());
		vect.push_back(tmp);
	}
	for (int i = 0; i < tmp.size(); i++) {
		map<string,int> str;
		bool flag = true;
		for (int j = 0; j < vect.size(); j++) {
			str[vect[j].substr(0, i + 1)]++;
			if (str[vect[j].substr(0, i + 1)] == 2) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << i+1;
			return 0;
		}
	}
	cout << tmp.size();
	return 0;
}