#include <bits/stdc++.h>
using namespace std;
int n;
string tmp;
int main() {
	cin >> n;
	regex re("(((10)0+1+)|(01))+");
	while (n--) {
		cin >> tmp;
		if (std::regex_match(tmp, re))
			cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}