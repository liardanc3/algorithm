#include <bits/stdc++.h>
using namespace std;
int main() {
	int cnt = 0;
	string tmp;
	while (cin >> tmp) {
		if (cin.eof())
			break;
		cnt++;
	}
	cout << cnt;
	return 0;
}