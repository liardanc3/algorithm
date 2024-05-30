#include <bits/stdc++.h>
using namespace std;

int main() {
	string tmp = "";
	for (int i = 0; i < 8; i++) {
		string a;
		cin >> a;
		tmp += a;
	}
	if (tmp == "12345678")
		cout << "ascending";
	else if (tmp == "87654321")
		cout << "descending";
	else
		cout << "mixed";
	
	return 0;
}