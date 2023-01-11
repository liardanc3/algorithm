#include <bits/stdc++.h>
using namespace std;
int main() {
	string tmp;
	while (cin >> tmp) {
		if (tmp == "0")
			break;
		bool flag = true;
		for (int i = 0; i < tmp.size() / 2; i++) {
			if (tmp[i] == tmp[tmp.size()-1 - i]) continue;
			else {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
	return 0;
}