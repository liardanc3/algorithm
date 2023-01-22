#include <bits/stdc++.h>
using namespace std;

int n, mx = 1e9, mn, dd, mm, yyyy;
string name, mxname, mnname;
int main() {
	cin >> n;
	while (n--) {
		cin >> name >> dd >> mm >> yyyy;
		int age = yyyy * 10000 + mm * 100 + dd;
		if (age < mx) {
			mxname = name;
			mx = age;
		}
		if (age > mn) {
			mnname = name;
			mn = age;
		}
	}
	cout << mnname << '\n' << mxname;

	return 0;
}