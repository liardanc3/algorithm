#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; string str, ans = "";
	cin >> N;
	vector<string> vect;
	while (N--) {
		cin >> str;
		vect.push_back(str);
	}
	for (int i = 0; i < str.size(); i++) {
		bool flag = true;
		for (int j = 0; j < vect.size()-1; j++) {
			if (vect[j][i] != vect[j + 1][i]) {
				flag = false;
				break;
			}
		}
		if (flag) ans += str[i];
		else ans += '?';
	}
	cout << ans;

	return 0;
}