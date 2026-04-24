#include <bits/stdc++.h>
using namespace std;
int n;
bool isBad(string str) {
	if (str.size() == 0) return false;
	for (int idx = 0; idx < str.size(); idx++) {
		for (int i = 1; idx+2*i <= str.size(); i++) {
			string a = str.substr(idx, i);
			string b = str.substr(idx + i, i);
			if (a == b)
				return true;
		}
	}
	return false;
}
void good(int len, string str) {
	if (isBad(str)) return;
	if (!isBad(str) && len == n) {
		cout << str;
		exit(0);
	}

	good(len + 1, str + "1");
	good(len + 1, str + "2");
	good(len + 1, str + "3");

}
int main() {
	cin >> n;
	good(0, "");

	return 0;
}